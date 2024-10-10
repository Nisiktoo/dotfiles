const int N = 200100;
std::vector<int> g[N];
int n, LOGN;
int timer;
std::vector<int> tin, tout;
std::vector<std::vector<int>> up; // up[i][j] = 2^j th ancestor of node i
/* ancestors of the root node is itself */
void dfs(int v, int fa) {
        tin[v] = ++timer;
        up[v][0] = fa;
        for (int i = 1; i <= LOGN; ++i) 
                up[v][i] = up[up[v][i-1]][i-1];

        for (int u : g[v]) {
                if (u != fa) dfs(u, v);
        }
        tout[v] = ++timer;
}
/* is u ancestor of v ? */
bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
}

/* lca of u and v */
int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = LOGN; i >= 0; i--) {
                if (!is_ancestor(up[u][i], v)) 
                        u = up[u][i];
        }

        return up[u][0];
}

void pre_process(int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        LOGN = std::ceil(log2(n));
        up.assign(n, std::vector<int> (LOGN+1));
        dfs(root, root);
}
