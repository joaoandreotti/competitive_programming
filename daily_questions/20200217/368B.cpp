#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

int n, m;
int arr [MAXN];
int q [MAXN];
int ans [MAXN];

void input () {
  scanf ("%d%d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  for (int i = 0; i < m; i++)
    scanf ("%d", q + i);

  solve ();
}

void solve () {
  std::set <int> set;

  for (int i = n - 1; i >= 0; i--) {
    set.insert (arr [i]);
    ans [i] = set.size ();
  }

  for (int i = 0; i < m; i++)
    printf ("%d\n", ans [q [i] - 1]);
}

int main () {
  input ();
  return 0;
}
