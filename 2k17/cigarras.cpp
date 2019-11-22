#include <bits/stdc++.h>

/*
long long lcm (int a, int b) {
  long long gcd = a, x = b;
  while (x) {
    gcd %= x;
    std::swap (gcd, x);
  }
  return (a * b) / gcd;

}
*/

long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

long long lcm(long long a, long long b) {
  return ((a * b)/ gcd(a, b));
}

int main () {
  int n, l;

  scanf ("%d%d", &n, &l);

  long long arr_lcm = 1;

  for (int i = 0; i < n; i++) {
    long long a;
    scanf ("%lld", &a);
    arr_lcm = lcm (arr_lcm, a);
  }

  long long ans, best = 0, aux;

  for (int i = 1; i <= l; i++) {
    aux = lcm(arr_lcm, i);
    if (best < aux && aux <= l) {
      best = aux;
      ans = i;
    }
  }

  printf ("%lld\n", ans);
  return 0;
}
