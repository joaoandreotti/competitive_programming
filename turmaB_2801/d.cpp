#include <bits/stdc++.h>

typedef std::vector <int> vi;
typedef std::vector <vi> graph;

const int MAXN = 1e5 + 1;

graph g;
int n, leafs, visited [MAXN];
long double dst [MAXN], ans;

void dfs (int x, int sz, int p) {
  visited [x] = 1;

  if (!(g [x].size () - 1) && x != 1) {
    ans += (1/(long double)p) * (long double)sz;
  }

  //printf ("x: %d, sz: %d, p: %d\n", x, sz, p);
  for (int v : g [x]) {
    if (!visited [v])
      if (x != 1)
        dfs (v, sz + 1, p * (g [x].size () - 1));
      else
        dfs (v, sz + 1, p * (g [x].size ()));
  }
}

int main () {
  scanf ("%d", &n);
  g.resize (MAXN);

  int a, b;
  for (int i = 0; i < (n - 1); i++) {
    scanf ("%d%d", &a, &b);
    g [a].push_back (b);
    g [b].push_back (a);
  }

  dfs (1, 0, 1);


  printf ("%.15Lf\n", ans);
  return 0;
}
