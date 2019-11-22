#include <bits/stdc++.h>

int main () {
  long long n, k;
  scanf ("%lld%lld", &n, &k);
  long long num_odd = n % 2 == 0 ? n / 2 : (n / 2) + 1;
  long long num_even = n / 2;

  if ((num_odd - k) >= 0) {
    printf ("%lld\n", (2 * k) - 1);
  }
  else {
    k -= num_odd;
    printf ("%lld\n", (2 * k));
  }
  return 0;
}
