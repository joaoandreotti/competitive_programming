#include <bits/stdc++.h>

int main () {
  int n;
  while (scanf ("%d", &n) != EOF) {
    long long sq = 4;
    for (int i = 2; i < n; i++)
      sq *= 2;

    long long sum = 0;
    int a;
    for (int i = 0; i < sq; i++) {
      scanf ("%d", &a);
      sum += a;
    }

    printf ("%lld\n", sum);
  }
  return 0;
}
