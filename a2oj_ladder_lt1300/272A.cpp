#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  n++;
  int a;
  long long sum = 0;
  for (int i = 0; i < n - 1; i++) {
    scanf ("%d", &a);
    sum += a;
  }

  long long ans = 0;
  for (int i = 1; i <= 5; i++) {
    if ((sum + i) % n != 1)
      ans++;
  }

  printf ("%lld\n", ans);
  return 0;
}
