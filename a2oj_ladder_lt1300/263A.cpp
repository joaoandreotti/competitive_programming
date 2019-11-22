#include <bits/stdc++.h>

int main () {
  long long ans = 0;
  int a;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf ("%d", &a);
      if (a == 1) {
        ans += abs(2 - i);
        ans += abs(2 - j);
      }
    }
  }
  printf ("%lld\n", ans);
  return 0;
}
