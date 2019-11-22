#include <bits/stdc++.h>

long long t, n, a, b;

long long check (long long a) {
  while (a) {
    if (a % 10 == 4)
      return 1;
    a /= 10;
  }
  return 0;
}

int main () {
  scanf ("%lld", &t);
  long long cnt = 1;
  while (t--) {
    scanf ("%lld", &n);
    a = n/2;
    b = n - a;

    // when a == 0 and b have 4s, boom TLE
    while (check (a) || check (b)) {
      b += (a - (a/2));
      a /= 2;
    }
    printf ("Case #%lld: %lld %lld\n", cnt++, a, b);
  }
  return 0;
}
