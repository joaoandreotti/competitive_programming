#include <bits/stdc++.h>

int main () {
  long long n, m;
  scanf ("%lld%lld", &n, &m);
  long long max = 0, maxp;

  for (int i = 0; i < n; i++) {
    long long a;
    scanf ("%lld", &a);
    a = (a / m) + ((a % m) > 0 ? 1 : 0);
    if (a >= max) {
      maxp = i + 1;
    }
  }
  printf ("%lld\n", maxp);
  return 0;
}
