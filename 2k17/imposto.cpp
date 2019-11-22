#include <bits/stdc++.h>

const int MAXN = (int)1e4 + 7;

int n;
double c;
std::vector <std::vector <std::pair <int, int> > > g;
int visited [MAXN];
int qtimp [MAXN];

long long ans;
void dfs (int crt, int father, int dist /*to father*/) {
  if (visited [crt]) return;
  visited [crt] = 1;
  for (auto x : g [crt]) {
    dfs (x.first, crt, x.second);
  }

  //printf ("crt: %d, dist: %d, qtimp: %d, c: %lf, eq: %d\n", crt, dist, qtimp [crt], c, dist * ((int)ceil ((qtimp [crt] * 1.0) / (c * 1.0))) * 2);
  // dist_to_father * numbers_of_trips * 2 (round trip)
  ans += dist * ((long long)ceil ((qtimp [crt] * 1.0) / (c * 1.0))) * 2;
  qtimp [father] += qtimp [crt];
  qtimp [crt] = 0;

}

int main () {
  scanf ("%d%lf", &n, &c);
  g.resize (n + 1);

  for (int i = 1; i <= n; i++)
    scanf ("%d", qtimp + i);

  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf ("%d%d%d", &a, &b, &c);
    g[a].push_back ({b, c});
    g[b].push_back ({a, c});
  }

  dfs (1, 0, 0);

  printf ("%lld\n", ans);

  return 0;
}
