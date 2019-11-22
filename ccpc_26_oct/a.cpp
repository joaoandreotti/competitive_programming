#include <bits/stdc++.h>

void input ();
void solve ();

int t, n, m;
int arr [101], brr [101];

void input () {
  scanf ("%d", &t);
  for (int cs = 0; cs < t; cs++) {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf ("%d", arr + i);
    for (int i = 0; i < m; i++)
      scanf ("%d", brr + i);
    solve ();
  }
}

void solve () {
  if (n <= m)
    puts ("Yes");
  else
    puts ("No");
}

int main () {
  input ();
  return 0;
}
