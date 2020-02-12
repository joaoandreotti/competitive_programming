#include <bits/stdc++.h>

void input ();
void solve ();

int x, y, k, n;

void input () {
  scanf ("%d%d%d", &y, &k, &n);

  solve ();
}

void solve () {
  if (y < n && (y + (k - (y % k))) <= n) {
    x = (k - (y % k));
    while (y + x <= n) {
      printf ("%d ", x);
      x += k;
    }
  }
  else
    puts ("-1");
}

int main () {
  input ();
  return 0;
}
