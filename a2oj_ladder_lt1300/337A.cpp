#include <bits/stdc++.h>

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  int arr [m];
  for (int i = 0; i < m; i++)
    scanf ("%d", arr + i);

  std::sort (arr, arr + m);

  int i = 0, j = n - 1;
  int ans = INT_MAX;
  while (j < m) {
    ans = std::min (arr [j] - arr [i], ans);
    i++; j++;
  }
  printf ("%d\n", ans);
  return 0;
}
