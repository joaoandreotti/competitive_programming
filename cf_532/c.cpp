#include <bits/stdc++.h>

const double PI = acos (-1);

int main () {
  double n, r; scanf ("%lf%lf", &n, &r);


  double R = 1; // 6 circles
  double c = (2 * PI * r);
  double sc = (2 * PI * 6.4641016) / c;

  double ans = (sc);

  printf ("ans: %.9lf\n",  ans);


  return 0;
}
