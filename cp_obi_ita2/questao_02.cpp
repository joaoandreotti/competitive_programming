#include <cstdio>
#include <cmath>

int main () {
  unsigned long long t, m, n;
  unsigned long long res;
  scanf ("%llu%llu%llu", &t, &n, &m);
  res = (m - n + 1) * (pow (2, t - 1));
  printf ("%llu\n", res);
  return 0;
}
