#include <bits/stdc++.h>

int main() {

  int a, b, c;
  scanf ("%d%d%d", &a, &b, &c);
  int d, e, f;
  scanf ("%d%d%d", &d, &e, &f);

  long long ans = 0;
  if (a - d < 0)
    ans += d - a;
  if (b - e < 0)
    ans += e - b;
  if (c - f < 0)
    ans += f - c;

  printf ("%lld\n", ans);

  return 0;
}
