#include <bits/stdc++.h>

#define pb push_back
const int N = 2e5+10;
int n, q, parent, u, k;
std::vector <int> graph[N], dfstab[N];
bool vis[N];

std::vector <int> dfs (int v) {
  std::vector <int> dfslist;
  dfslist.pb(v);
  vis[v] = true;

  for (int u : graph[v]) {
    if (!vis[u]) {
      dfstab[u] = dfs(u);
      for (int x : dfstab[u])
        dfstab[v].pb(x);
    }
  }

  return dfslist;
}

int main () {
  scanf("%d%d", &n, &q);

  for (int i = 0; i < n-1; i++) {
    scanf("%d", &parent);
    graph[parent-1].pb(i);
  }

  dfstab[0] = dfs(0);

  for (int i = 0; i < q; i++) {
    scanf("%d%d", &u, &k);
    printf("%d\n", dfstab[u-1].size() < k ? dfstab[u-1][k-1] + 1 : -1);
  }

  return 0;
}
