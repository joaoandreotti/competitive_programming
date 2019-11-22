#include <bits/stdc++.h>

int main () {
  int n, k, l, c, d, p, nl, np;
  scanf ("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);

  int drinks, limes, salts;
  drinks = (k * l) / nl;
  limes = c*d;
  salts = p / np;

  std::cout << std::min (drinks, std::min (limes, salts)) / n << '\n';
}
