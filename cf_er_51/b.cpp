#include <bits/stdc++.h>

int v [3 * (int)1e5];

int gcd (int a, int b) {
  while (b) {
    a %= b;
    std::swap (a, b);
  }
  return a;
}

int main () {
  long long l, r;

  scanf ("%lld%lld", &l , &r);

  printf ("YES\n");

  for (long long i = l; i < r; i += 2) {
    printf ("%lld %lld\n", i, i + 1);
  }

  
  return 0;
}
