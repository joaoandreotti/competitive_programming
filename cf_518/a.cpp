#include <bits/stdc++.h>

int main () {
  double n, m, k, l;
  scanf ("%lf%lf%lf%lf", &n, &m, &k, &l);

  if (n == k) {
    puts ("-1");
    return 0;
  }

  double x = ceil((l + k) / (m * 1.0));

  if ((x * m) < n) {
    printf ("%.0lf\n", x);
  }
  else if (m == 1) {
    printf ("%.0lf\n", n);
    return 0;
  }
  else {
    puts ("-1");
  }

  return 0;
}
