#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  long long max, min;
  scanf ("%lld", &max);
  min = max;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    int a;
    scanf ("%d", &a);
    if (a > max) {
      max = a;
      ans++;
    }
    if (a < min) {
      min = a;
      ans++;
    }
  }

  printf ("%lld\n", ans);
  return 0;
}
