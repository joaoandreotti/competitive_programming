#include <bits/stdc++.h>

int arr [(2 * (int)1e5) + 10];

void sum (int a) {
  for (int i = 1; i <= a; i++)
    arr [i] += i;

  for (int i = 2; i <= a; i++)
    arr [i] += arr [i - 1];
}

int main () {
  long long n, m;
  scanf ("%lld%lld", &n, &m);
  sum (n);

  int i = 0;
  long long res = 0;
  while (i <= n && arr [i] <= m) {
    res = arr [i];
    i++;
  }

 if (m > 0) {
    if (m * 2 <= n)
      printf ("%lld %lld\n", n - (2 * m), (n - i) - (((m - res) / i) + ((m - res) % i)));
    else
      printf ("%lld %lld\n", 0, (n - i) - (((m - res) / i) + ((m - res) % i)));
  }
  else {
    printf ("%lld %lld\n", n, (n - i) - (((m - res) / i) + ((m - res) % i)));
  }

  return 0;
}
