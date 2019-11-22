#include <bits/stdc++.h>

int main () {
  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    std::string a, b;
    std::cin >> a >> b;

    int sa = a.size (), sb = b.size ();

    for (int i = 0; i < a.size (); i++) {
      if (a [i] == '.')
        sa = i;
    }

    for (int i = 0; i < b.size (); i++) {
      if (b [i] == '.')
        sb = i;
    }

    int posa = a.size () - sa, posb = b.size () - sb;
    int num = std::max (posa, posb);

    int x = 0, y = 0;

    for (int i = 0; i < a.size (); i++) {
      if (a [i] == '.')
        continue;
      x += a [i] - '0';

      if (i + 1 < a.size ())
        x *= 10;
    }

    for (int i = 0; i < b.size (); i++) {
      if (b [i] == '.')
        continue;
      y += b [i] - '0';

      if (i + 1 < a.size ())
        y *= 10;
    }

    for (int i = 0; i < num - posa; i++) {
      x *= 10;
    }

    for (int i = 0; i < num - posb; i++) {
      y *= 10;
    }
    printf ("x: %d, y: %d\n", x, y);
  }
  return 0;
}
