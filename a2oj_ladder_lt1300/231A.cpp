#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf ("%d%d%d", &a, &b, &c);
    if (a == 1 && (b == 1 || c == 1))
      ans++;
    else if (b == 1 && (a == 1 || c == 1))
      ans++;
    else if (c == 1 && (a == 1 || b == 1))
      ans++;
  }
  printf ("%lld\n", ans);
  return 0;
}
