#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  int a;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    scanf ("%d", &a);
    ans += a;
  }
  printf ("%lf\n", ans / (1.0 * n));
  return 0;
}
