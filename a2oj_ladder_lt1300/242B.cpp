#include <bits/stdc++.h>

std::set <std::pair <int, int> > set;

int main () {
  int n; scanf ("%d", &n);
  int l = 0x3f3f3f3f, r = 0;
  int pos = 0;
  for (int i = 0; i < n; i++) {
    int a, b; scanf ("%d%d", &a, &b);
    set.insert ({a, b});

    if (a <= l && b >= r) {
      l = a;
      r = b;
      pos = i + 1;
    }
  }

  int lf = 0, rf = 0;
  for (auto i = set.begin (); i != set.end (); i++) {
    if (i->first < l)
      lf = 1;
    else if (i->second > r)
      rf = 1;
  }

  if (lf || rf)
    puts ("-1");
  else
    printf ("%d\n", pos);

  return 0;
}
