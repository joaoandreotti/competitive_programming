#include <bits/stdc++.h>

const int MAXN = 1e2 + 1;

int n, arr [MAXN];

int main () {
  scanf ("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf ("%d", arr + i);
    sum += arr [i];
  }

  std::sort (arr, arr + n);

  long long ans = 0, crr = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (crr <= (sum / 2)) {
      ans++;
      crr += arr [i];
    }
  }

  printf ("%lld\n", ans);

  return 0;
}
