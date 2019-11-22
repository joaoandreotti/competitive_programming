#include <bits/stdc++.h>

int main () {
  int t;
  scanf ("%d", &t);
  
  for (int tc = 0; tc < t; tc++) {
    long long s, a, b, c;
    scanf ("%lld%lld%lld%lld", &s, &a, &b, &c);

    printf ("%lld\n", (((s / c) / a) * b) + (s / c));
  }
  return 0;
}
