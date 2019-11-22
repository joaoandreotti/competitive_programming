#include <bits/stdc++.h>

void input ();
void solve ();

int t, a, b;

void input () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d%d", &a, &b);
    solve ();
  }
}

void solve () {
  int c = std::abs (a - b);

  int ans = 0;

  ans += c / 5;
  c = c % 5;

  ans += c / 2;
  c = c % 2;

  ans += c / 1;
  c = c % 1;

  printf ("%d\n", ans);
}

int main () {
  input ();
  return 0;
}
