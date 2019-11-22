#include <bits/stdc++.h>

int main () {
  int tc;
  while (scanf ("%d", &tc) && tc != 0) {
    int x, y; scanf ("%d%d", &x, &y);
    for (int i = 0; i < tc; i++) {
      int a, b; scanf ("%d%d", &a, &b);

      if (a == x || b == y)
        puts ("divisa");
      else if (a > x && b > y)
        puts ("NE");
      else if (a > x && b < y)
        puts ("SE");
      else if (a < x && b < y)
        puts ("SO");
      else if (a < x && b > y)
        puts ("NO");

    }
  }
  return 0;
}
