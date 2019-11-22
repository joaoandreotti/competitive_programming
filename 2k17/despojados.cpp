#include <bits/stdc++.h>

int prime (long long a) {
  for (int i = 2; i < a; i++)
    if (a % i == 0)
      return 0;
  return 1;
}

int main () {
  long long unsigned n, aux;

  scanf ("%llu", &n);
  aux = n;

  long long ans = 0, count = 0;
  for (long long i = 2; i < sqrt (n); i++) {
    if (prime (i)) {
      if (count == 1)
        ans++;
      if (aux % i == 0) {
        aux /= i;
        i--;
        count++;
        continue;
      }
    }
    count = 0;
  }

  printf ("%lld\n", ans);

  return 0;
}
