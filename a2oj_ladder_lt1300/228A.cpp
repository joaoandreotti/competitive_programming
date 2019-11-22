#include <bits/stdc++.h>

std::set <int> set;

int main () {
  int a, b, c, d;
  scanf ("%d%d%d%d", &a, &b, &c, &d);
  set.insert (a);
  set.insert (b);
  set.insert (c);
  set.insert (d);
  printf ("%d\n", 4 - set.size ());
  return 0;
}
