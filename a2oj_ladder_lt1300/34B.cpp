#include <bits/stdc++.h>

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  int arr[n];
  for (int i = 0; i < n; i++)
    scanf ("%d", arr +i);
  std::sort (arr, arr + n);
  long long ans = 0, tvs = 0;
  for (int i = 0; i < n; i++)
    if (tvs < m && ans + arr[i] < ans) {
      ans += arr[i];
      tvs++;
    }

  printf ("%lld\n", abs(ans));
  return 0;
}
