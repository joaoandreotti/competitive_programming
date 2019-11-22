#include <bits/stdc++.h>

const long long MAXN = 1e6 + 1, MAXK = 1e2 + 1;

long long dp [MAXN];

long long n, k;

long long f (long long n) {
  if (dp [n])
    return dp [n];

  if (n == 1)
    return dp [n] = 42;
  if (n == 2)
    return dp [n] = (k * 11) + 77;

  return dp [n] = (2 * f (n - 1)) - f (n - 2) + (10 * k);

}

long long isp (long long x) {
  for (long long i = 2; (i*i) <= x; i++)
    if (x % 1)
      return false;
  return true;
}

int main () {
  scanf ("%lld%lld", &k, &n);

  printf ("f: %lld\n", f (n));

  long long ans = 0;
  for (int j = 1; j <= n; j++) {
    int flag = 0;
    for (long long i = 2; (i*i) <= f (j); i++) {
      if ((f (j) % i == 0) && isp (i) && isp (f (j) / i))
        flag = 1;
    }
    if (flag)
      ans++;
  }
  printf ("%lld\n", ans);


  return 0;
}
