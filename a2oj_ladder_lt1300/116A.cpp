#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);

  long long max = 0, crr = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf ("%d%d", &a, &b);
    crr -= a;
    crr += b;
    if (crr > max)
      max = crr;
  }

  printf ("%lld\n", max);
  return 0;
}
