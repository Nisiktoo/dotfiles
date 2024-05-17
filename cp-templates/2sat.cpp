#include <bits/stdc++.h>
int n; // n 2 * number of vertices
/* adj : graph of implication
 * adj_t : the transpose graph of adj (in which the direction of each edge is reversed)
*/
std::vector<std::vector<int>> adj, adj_t;
std::vector<bool> used, assignment;
std::vector<int> order, comp;

/* p v q = not p -> q and not q -> p */
/* In the graph the vertices with indices 2k and 2k+1 are the two vertices
 * corresponding to variable k with 2k+1 corresponding to the negated variable.
*/
/* a and b are two boolean var and na and nb are just negation operator */
/* (a, 0, b, 0) == a v b 
 * (a, 1, b, 0) == not a v b
 * (a, 0, b, 1) == a v not b 
*/
void add_disjunction(int a, bool na, int b, bool nb) {
  // na and nb signify whether a and b are to be negated
  a = 2*a ^ na;
  b = 2*b ^ nb;
  int neg_a = a ^ 1;
  int neg_b = b ^ 1;
  adj[neg_a].push_back(b);
  adj[neg_b].push_back(a);
  adj_t[b].push_back(neg_a);
  adj_t[a].push_back(neg_b);
}
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

void dfs2(int v, int cl) {
  comp[v] = cl;
  for (int u : adj_t[v]) {
    if (comp[u] == -1) {
      dfs2(u, cl);
    }
  }
}

bool solve_2SAT() {
  order.clear();
  used.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs1(i);
    }
  }
  comp.assign(n, -1);
  for (int i = 0, j = 0; i < n; i++) {
    int v = order[n-1-i];
    if (comp[v] == -1) {
      dfs2(v, j++);
    }
  }

  assignment.assign(n/2, false);
  for (int i = 0; i < n; i += 2) {
    if (comp[i] == comp[i+1]) {
      return false;
    }
    assignment[i/2] = comp[i] > comp[i+1];
  }
  return true;
}
