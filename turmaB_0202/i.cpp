#include <bits/stdc++.h>

const int MAXN = 2e5 + 1;

int arr [MAXN];

int main () {
  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  long long ans = abs (arr [0]), crr = arr [0];
  for (int i = 1; i < n; i++) {
    ans += abs (crr - arr [i]);
    crr = arr [i];
  }

  printf ("%lld\n", ans);

  return 0;
}
