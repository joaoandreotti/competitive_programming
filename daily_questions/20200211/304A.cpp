#include <bits/stdc++.h>

void input ();
void solve ();

const double EPS = 1e-9;

int n;

void input () {
  scanf ("%d", &n);
  solve ();
}

void solve () {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      if (sqrt ((i * i) + (j * j)) - (int)sqrt ((i * i) + (j * j)) < EPS && (int)sqrt ((i * i) + (j * j)) <= n) {
        ans++;
        //printf ("%d = %d + %d\n", (int)sqrt ((i * i) + (j * j)), i, j);
      }

  printf ("%d\n", ans);
}

int main () {
  input ();
  return 0;
}
