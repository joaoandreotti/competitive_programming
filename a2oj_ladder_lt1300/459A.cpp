#include <bits/stdc++.h>

int main () {
  int xa, ya, xb, yb;
  scanf ("%d%d%d%d", &xa, &ya, &xb, &yb);

  if (ya == yb) {
    if (ya + abs(xa - xb) <= 1000)
      printf ("%d %d %d %d\n", xa, ya + abs(xa - xb), xb, yb + abs(xa - xb));
    else
      printf ("%d %d %d %d\n", xa, ya - abs(xa - xb), xb, yb - abs(xa - xb));
  }
  else if (xa == xb) {
    if (xa + abs(ya - yb) <= 1000)
      printf ("%d %d %d %d\n", xa + abs(ya - yb), ya, xb + abs(ya - yb), yb);
    else
      printf ("%d %d %d %d\n", xa - abs(ya - yb), ya, xb - abs(ya - yb), yb);
  }
  else {
    if (abs(xa - xb) != abs(ya- yb)) {
      puts ("-1");
      return 0;
    }
    if (ya < yb)
      printf ("%d %d %d %d\n", xa, ya + abs(xa - xb), xb, yb - abs(xa - xb));
    else
      printf ("%d %d %d %d\n", xa, ya - abs(xa - xb), xb, yb + abs(xa - xb));
  }
  return 0;
}
