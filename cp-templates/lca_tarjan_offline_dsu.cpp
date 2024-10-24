#include <bits/stdc++.h>
#ifdef DEBUG
#include <debug.h>
#else 
#define dbg(x...)
#endif
#define sci(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define sci2(x, y) scanf("%d %d", &x, &y)
#define sci3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sci4(x, y, z, k) scanf("%d %d %d %d", &x, &y, &z, &k)
#define scl(x) scanf("%lld", &x)
#define scl2(x, y) scanf("%lld %lld", &x, &y)
#define scl3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define scl4(x, y, z, k) scanf("%lld %lld %lld %lld", &x, &y, &z, &k)
#define pri(x) printf("%d ", x)
#define prl(x) printf("%lld ", x)
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pil = std::pair<int, ll>;
using pll = std::pair<ll, ll>;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<pii> vpii;
typedef std::vector<pil> vpil;
typedef std::vector<pll> vpll;
typedef std::vector<bool> vb;
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define nl putchar('\n')
#define ins insert
#define RET return

struct dsu {
  private:
  std::vector<int> _parent, Size;
  public:
    dsu() {
    }
    dsu(int _sz) {
      _parent.resize(_sz+1);
      Size.resize(_sz+1);
      for (int i = 0; i <= _sz; i++) {
        _parent[i] = i;
        Size[i] = 1;
      }
    }
    void union_set(int _a, int _b) {
      _a = find_set(_a);
      _b = find_set(_b);
      if (_a != _b) {
        if (Size[_a] < Size[_b]) {
          std::swap(_a, _b);
        }
        _parent[_b] = _a;
        Size[_a] += Size[_b];
      }
    }
    int find_set(int _v) {
      if (_v == _parent[_v]) {
        return _v;
      }
      return _parent[_v] = find_set(_parent[_v]);
    }
};
std::vector<std::vector<int>> queries;
std::vector<int> ancestor;
std::vector<bool> visited;

void dfs(int v, int fa) {
        ancestor[v] = v;
        visited[v] = true;
        for (int u : g[v]) {
                if (!visited[u]) {
                        dfs(u, v);
                        union_sets(v, u);
                        ancestor[find_set(v)] = v;
                }
        }
        for (int other_node : queries[v]) {
                if (visited[other_node]) {
                        printf("LCA of v and other_node = %d\n", ancestor[find_set(other_node)]);
                }
        }
}
void compute_LCAs() {
        // initialize n, adj, and DSU
        // for (each query (u, v)) {
        //      queries[u].push_back(v);
        //      queries[v].push_back(u);
        //      }

        ancestor.resize(n);
        dfs(0, -1);
}
