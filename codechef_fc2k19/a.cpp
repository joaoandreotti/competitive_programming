#include <bits/stdc++.h>

long long lcm (long long a, long long b) {
  return ((a*b) / std::__gcd (a, b));
}

int main () {
  int t; scanf ("%d", &t);

  while (t--) {
    long long n, a, b, k;
    scanf ("%lld%lld%lld%lld", &n, &a, &b, &k);
    long long x = ((n / a) - (n / lcm (a, b))) + ((n / b) - (n / lcm (a, b)));

    //printf ("n/a: %lld, n/b: %lld, n/lcm: %d\n", (n / a), (n / b), (n / lcm (a, b)));

    if (x >= k)
      puts ("Win");
    else
      puts ("Lose");
  }

  return 0;
}
