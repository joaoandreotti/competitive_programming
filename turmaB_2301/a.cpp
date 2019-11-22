#include <bits/stdc++.h>

#define int long long

int b, p, m;


int f (int b,  int exp) {
  int ans = 1;

  if (exp == 0)
    return 1;

  ans = (f (b, exp / 2) * f (b, exp / 2)) % m;

  if (exp % 2)
    ans *= b;

  return ans % m;
}

int32_t main () {

  while (scanf ("%lld%lld%lld", &b, &p, &m) != EOF) {
    printf ("%lld\n", f (b, p));
  }

  return 0;
}
