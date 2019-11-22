#include <bits/stdc++.h>

void input ();
void solve ();

int t;
int n, x, a, b;

void input () {
  scanf ("%d", &t);
  for (int cs = 0; cs < t; cs++) {
    scanf ("%d%d%d%d", &n, &x, &a, &b);
    solve ();
  }
}

void solve () {
  if (a > b)
    std::swap (a, b);
  for (; a > 1 && x; a--) {
    x--;
  }

  for (; b < n && x;) {
    x--;
    b++;
  }

  printf ("%d\n", b - a);
}

int main () {
  input ();
  return 0;
}
