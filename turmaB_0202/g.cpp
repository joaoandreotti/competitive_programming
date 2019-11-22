#include <bits/stdc++.h>

int main () {
  int a, b, c; scanf ("%d%d%d", &a, &b, &c);
  b /= 2;
  c /= 4;

  if (a && b && c) {
    int cmpt = std::min (a, std::min (b, c));
    printf ("%d\n", cmpt + (cmpt * 2) + (cmpt * 4));
  }
  else
    puts ("0");
  return 0;
}
