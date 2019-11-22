#include <bits/stdc++.h>


int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  int minarr [m], maxarr [m];
  for (int i = 0; i < m; i++) {
    scanf ("%d", minarr + i);
    maxarr [i] = minarr [i];
  }
  int st = 0;
  long long min = 0, max = 0;

  for (int j = 0; j < n; j++) {
    std::sort (maxarr, maxarr + m);
    min += minarr [0]--;
    if (!minarr [0])
      minarr [0] = INT_MAX;
  }

  st = 0;
  for (int j = 0; j < n; j++) {
    std::sort (maxarr, maxarr + m, std::greater <int>());
    max += maxarr [0]--;
  }
  printf ("%lld %lld\n", max, min);
  return 0;
}
