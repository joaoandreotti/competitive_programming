#include <bits/stdc++.h>

struct flow_edge {
  int v, u; // flow from 'v' to 'u'
  long long cap, flow = 0; // cap is the max flow in this edge
  flow_edge (int v, int u, long long cap) : v (v), u (u), cap (cap) {}
};

const long long flow_inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
int s, t;

std::vector <flow_edge> edges;
std::vector <std::vector <int> > adj;
std::vector <int> level, ptr;
std::queue <int> q;

void dinic (int n1, int s1, int t1) {
  n = n1; s = s1; t = t1;
  adj.resize (n);
  level.resize (n);
  ptr.resize (n);
}

void add_edge (int v, int u, long long cap) {
  edges.push_back (flow_edge (v, u, cap));
  edges.push_back (flow_edge (u, v, 0));
  adj [v].push_back (m);
  adj [u].push_back (m + 1);
  m += 2;
}

bool bfs () {
  while (!q.empty ()) {
    int v = q.front ();
    q.pop ();
    for (int id : adj [v]) {
      if (edges [id].cap - edges [id].flow < 1)
        continue;
      if (level [edges [id].u] != -1)
        continue;
      level [edges [id].u] = level [v] + 1;
      q.push (edges [id].u);
    }
  }
  return level [t] != -1;
}

long long dfs (int v, long long pushed) {
  if (pushed == 0)
    return 0;
  if (v == t)
    return pushed;

  for (int &cid = ptr [v]; cid < (int)adj [v].size (); cid++) {
    int id = adj [v][cid];
    int u = edges [id].u;

    if (level [v] + 1 != level [u] || edges [id].cap - edges [id].flow < 1)
      continue;
    long long tr = dfs (u, std::min (pushed, edges [id].cap - edges [id].flow));
    if (tr == 0)
      continue;
    edges [id].flow += tr;
    edges [id ^ 1].flow -= tr;
    return tr;
  }
  return 0;
}

long long flow () {
  long long f = 0;
  while (true) {
    std::fill (level.begin (), level.end (), -1);
    level [s] = 0;
    q.push (s);
    if (!bfs ())
      break;
    std::fill (ptr.begin (), ptr.end (), 0);
    while (long long pushed = dfs (s, flow_inf)) {
      f += pushed;
    }
  }
  return f;
}

int main () {
  int n1, m1; scanf ("%d%d", &n1, &m1);
  dinic (n1 + m1 + 2, 0, n1 + m1 + 1);

  for (int i = 0; i < n1; i++) {
    int a; scanf ("%d", &a);
    add_edge (0, i + 1, 1);
    for (int j = 0; j < a; j++) {
      int b; scanf ("%d", &b);
      add_edge (i + 1, n1 + b, flow_inf);
    }
  }
  for (int i = n1 + 1; i <= (n1 + m1); i++)
    add_edge (i, (n1 + m1) + 1, 1);

  /*puts ("edges:");
  for (auto x : edges) {
    printf ("{%d, %d, %d}\n", x.v, x.u, x.cap);
  }
  puts ("----");
  */

  printf ("%lld\n", flow ());

  return 0;
}
