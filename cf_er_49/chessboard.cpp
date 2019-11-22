#include <iostream>
#include <stdio.h>

int main () {
  long long n, k;
  long long x, y;
  long long pos;

  scanf ("%lld%lld", &n, &k);

  for (int i = 0; i < k; i++) {
    scanf ("%lld%lld", &x, &y);
    //printf ("pos: %lld\n", pos);
    x--; y--;
    pos = (x * n) + y;
    if ((x + y) % 2 == 0) {
      printf ("%lld\n", (pos/2) + 1);
    }
    else {
      long long max = n % 2 == 0 ? (n * n / 2) : (n * n / 2) + 1;
      printf ("%lld\n", (pos/2) + 1 + max);
    }
  }

  return 0;
}
