#include <bits/stdc++.h>

int main () {
  int T; scanf ("%d", &T);

  while (T--) {
    long long a, b, k;
    scanf ("%lld%lld%lld", &a, &b, &k);

    long long jmp = a - b;
    
    if (k % 2 == 0) {
      printf ("%lld\n", jmp * (k / 2));
    }
    else {
      printf ("%lld\n", (jmp * (k / 2)) + a);
    }
  }
  return 0;
}
