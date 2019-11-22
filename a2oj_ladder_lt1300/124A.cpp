#include <bits/stdc++.h>

int main () {
  int n, a, b;
  scanf ("%d%d%d", &n, &a, &b);
  n -= a;

  printf ("%d\n", std::min (b + 1, n));
  return 0;
}
