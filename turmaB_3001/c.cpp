#include <bits/stdc++.h>

int main () {
  long long n, k;
  
  while (scanf ("%lld%lld", &n, &k) != EOF) {

    long long ans = n;

    while (n - k >= 0) {
      ans++;
      n -= k;
      n++;
    }

    printf ("%lld\n", ans);
  }
  return 0;
}
