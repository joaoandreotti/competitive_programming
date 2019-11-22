#include <bits/stdc++.h>

int main () {
  int x, y, z; scanf ("%d%d%d", &x, &y, &z);
  int a, b, c; scanf ("%d%d%d", &a, &b, &c);

  if (c >= z)
    z = 0;
  else
    z -= c;

  if (z > 0  && b >= z) {
    z = 0;
    b -= z;
  }
  else if (z > 0  && b < z) {
    b = 0;
    z -= b;
  }

  if (z > 0  && a >= z) {
    z = 0;
    a -= z;
  }
  else if (z > 0  && a < z) {
    a = 0;
    z -= a;
  }

  if (b >= y)
    y = 0;
  else
    y -= b;

  if (y > 0 && a >= y) {
    y = 0;
    a -= y;
  }
  else if (y > 0  && a < y) {
    y -= a;
  }

  if (a >= x)
    x = 0;
  else
    x -= a;

  if (x <= 0 && y <= 0 && z <= 0)
    puts ("YES");
  else
    puts ("NO");


  return 0;
}
