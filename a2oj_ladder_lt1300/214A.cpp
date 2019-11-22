#include <bits/stdc++.h>

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if ((int)pow (i, 2) + j == n && (int)pow (j, 2) + i == m) {
        ans++;
      }
    }
  }
  printf ("%lld\n", ans);
  return 0;
}
