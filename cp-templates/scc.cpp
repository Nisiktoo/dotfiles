/* adj_rev is transposed (edges reversed) graph
 * make sure to clear and resize adj and adj_rev and used array
*/
std::vector<std::vector<int>> adj, adj_rev;
std::vector<bool> used;
std::vector<int> order, component;
/* Function dfs1 fills the list order with vertices in increasing order of their exit times */
void dfs1(int v) {
  used[v] = true;

  for (auto u : adj[v]) {
    if (!used[u]) {
      dfs1(u);
    }
  }
  order.push_back(v);
}

/* Function dfs2 stores all reached vertices in list component, that is going to store next strongly connected component after each run */
void dfs2(int v) {
  used[v] = true;
  component.push_back(v);

  for (auto u : adj_rev[v]) {
    if (!used[u]) {
      dfs2(u);
    }
  }
}
// Condensation Graph Implementation
/** Move it inside a function **/
/*
  std::vector<int> roots(n, 0), root_nodes;
  std::vector<std::vector<int>> adj_scc(n);

  for (auto v : order) {
    if (!used[v]) {
      dfs2(v);
      int root = component.front();
      for (auto u : component) roots[u] = root;
      root_nodes.push_back(root);
      component.clear();
    }
  }
  for (int v = 0; v < n; v++) {
    for (auto u : adj[v]) {
      int root_v = roots[v],
          root_u = roots[u];
      if (root_u != root_v) {
        adj_scc[root_v].push_back(root_u);
      }
    }
  }
*/
