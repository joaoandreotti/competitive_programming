#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

std::vector <std::vector <int> > g;

int n, m;
int visited [MAXN];
int min, max;

void dfs (int x) {
  visited [x] = 1;

  min = std::min (min, x);
  max = std::max (max, x);
  for (int v : g [x])
    if (!visited [v])
      dfs (v);
}


void input () {
  scanf ("%d%d", &n, &m);
  g.resize (n);

  for (int i = 0, a, b; i < m; i++) {
    scanf ("%d%d", &a, &b);
    a--; b--;

    g [a].push_back (b);
    g [b].push_back (a);
  }

  solve ();
}

void solve () {
  std::vector <std::pair <int, int> > ranges;
  for (int i = 0; i < n; i++)
    if (!visited [i]) {
      min = max = i;
      dfs (i);
      ranges.push_back ({min, max});
    }

  std::sort (ranges.begin (), ranges.end ());

  int crr = -1;
  int ans = 0;
  for (int i = 0; i < ranges.size (); i++) {
    if (ranges [i].first <= crr)
      ans++;

    crr = std::max (crr, ranges [i].second);
  }

  printf ("%d\n", ans);
}

int main () {
  input ();
  return 0;
}
