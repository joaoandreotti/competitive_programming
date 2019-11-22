#include <bits/stdc++.h>

void input ();
void solve ();

int n;
int a, b, c, d, k;

void input () {
  scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf ("%d%d%d%d%d", &a, &b, &c, &d, &k);
    solve ();
  }
}

void solve () {
  int x = (a / c) + (a % c != 0);
  int y = (b / d) + (b % d != 0);

  if (x + y <= k)
    printf ("%d %d\n", x, y);
  else
    puts ("-1");
}

int main () {
  input ();
  return 0;
}
