#include <bits/stdc++.h>

long long dp [(int)1e6];

const long long mod = pow (2, 30);

long long sum (long long a) {
  if (dp [a])
    return dp[a];

  long long res = 2;
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0 && a / i != i)
      res += 2;
    else if (a % i == 0)
      res++;
  if (a == 1)
    res--;

  dp [a] = res;
  return res;
}

int main () {
  long long ans = 0;
  int a, b, c;
  scanf ("%d%d%d", &a, &b, &c);

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        ans += sum (i * j * k) % mod;
      }
    }
  }

  printf ("%lld\n", ans % mod);

  return 0;
}
