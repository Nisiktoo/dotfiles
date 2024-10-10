const int N = 200100;
/* height[i] = depth of node i from the root node
 * first[i] = firt occurence (index) of node i in the vector euler */
int height[N], first[N];
std::vector<int> euler; // euler tour
std::vector<int> g[N];
int n;

void lca_dfs(int v, int h = 0, int fa = -1) {
        height[v] = h;
        first[v] = euler.size();
        euler.push_back(v);
        for (int adj : g[v]) {
                if (adj != fa) {
                        lca_dfs(adj, h+1, v);
                        euler.push_back(v);
                }
        }
}

const int MAXN = 400100, K = 25; /* MAXN = max array length, K >= lg(MAXN) */
int st[K+1][MAXN]; /* st[i][j] storens answer of the range [j, j + 2^i - 1] */
int log2_floor(unsigned long long i) {
	return i ? __builtin_clzll(1) - __builtin_clzll(i) : 1;
}

/* usage :
 * i = log2_floor(r-l+1)
 * ans = f(st[i][l], st[i][r-(1<<i) + 1)
*/

/* sparse table stores the node with min height */
void precompute_sparse_table_lca() {
	std::copy(euler.begin(), euler.end(), st[0]);
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j + (1 << i) <= (int) euler.size(); j++) {
                        int l = st[i - 1][j], r = st[i - 1][j + (1 << (i - 1))];
			st[i][j] = height[l] < height[r] ? l : r;
		}
	}
}
/* find the lca(u, v) */
int lca(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r) std::swap(l, r);
        int i = log2_floor(r-l+1);
        int lv = st[i][l], rv = st[i][r - (1 << i) + 1];
        return (height[lv] < height[rv]) ? lv : rv;
}
