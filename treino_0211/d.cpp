#include <bits/stdc++.h>

void input ();
void solve ();

int movx [4] = {1, -1, 0, 0};
int movy [4] = {0, 0, 1, -1};

const int MAXN = 1e2 + 1;

int t, cs, n, m;
long long path [MAXN][MAXN];
long long vis [MAXN][MAXN];

void input () {
  scanf ("%d", &t);
  for (cs = 1; cs <= t; cs++) {
    scanf ("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf ("%d", path [i] + j);

    solve ();
  }
}

void solve () {
  printf ("Caso #%d : CUSTO: %lld\n", cs, min);
}

int main () {
  input ();
  return 0;
}
