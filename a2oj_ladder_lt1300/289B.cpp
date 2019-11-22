#include <bits/stdc++.h>

int main () {
  long long n, m, k;
  scanf ("%lld%lld%lld", &n, &m, &k);
  int arr [(n * m)];
  for (int i = 0; i < (n * m); i++)
    scanf ("%d", arr + i);
  std::sort (arr, arr + n + m);

  int mod = arr [0] % k;
  for (int i = 1; i < (n * m); i++) {
    if ((arr [i] % k) != mod) {
      puts ("-1");
      return 0;
    }
  }

  long long min = LONG_MAX, sum = 0;
  for (int i = 0; i < (n * m); i++) {
    sum = 0;
    for (int j = 0; j < (n * m); j++)
      sum += abs(arr [j] - arr [i]) / k;
    min = std::min (sum, min);
  }

  printf ("%lld\n", min);
  return 0;
}
