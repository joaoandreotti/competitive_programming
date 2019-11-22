#include <bits/stdc++.h>

int main () {
  long long n; scanf ("%lld", &n);

  long long ans = (n + 1) * n / 2;

  if (ans % 2)
    puts ("1");
  else
    puts ("0");

  return 0;
}
