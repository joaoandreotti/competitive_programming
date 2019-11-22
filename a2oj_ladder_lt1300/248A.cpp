#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  int left_open = 0, right_open = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf ("%d%d", &a, &b);
    left_open += a;
    right_open += b;
  }

  long long ans = 0;
  if (n - left_open >= left_open)
    ans += left_open;
  else
    ans += n - left_open;

  if (n - right_open >= right_open)
    ans += right_open;
  else
    ans += n - right_open;

  printf ("%lld\n", ans);

  return 0;
}
