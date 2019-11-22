#include <bits/stdc++.h>

void input ();
void sol ();

void input () {
  scanf ("%d", &tc);
  scanf ("%d%d%d%d", &n, &m, &h, &v);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf ("%c", arr [i] + j);
}

void sol () {
}

int cc (pi x, pi i) {
  int cnt = 0;
  for (int i = x.first; i < y.first; i++)
    for (int j = x.second; j < y.second; j++)
      if (arr [i][j])
        cnt++;

  return cnt;
}

int f (int h, int v, pi x, pi y) {
  if (!h && !v)
    return cc (x, y);


  for (int i = 0; i < n; i++) {
    if (f (h - 1, v, x, y) ==  f (h, v - 1, x, y))
      return 1;
  }

  return 0;
}

int main () {
  return 0;
}
