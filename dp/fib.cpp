#include <bits/stdc++.h>

int dp [46]; // 46 int size

int fib_nodp (int a) {
  if (a == 1)
    return 1;
  if (a == 0)
    return 0;

  return fib (a - 1) + fib (a - 2);
}

int fib (int a) {
  if (a == 1)
    return 1;
  if (a == 0)
    return 0;

  if (dp [a])
    return dp[a];

  return dp[a] = fib (a - 1) + fib (a - 2);
}

int main () {
  dp [0] = 0;
  dp [1] = 1;
  fib (46);
  printf ("%d\n", dp[46]);
  return 0;
}
