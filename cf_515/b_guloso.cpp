#include <bits/stdc++.h>

std::vector <int> h;
std::vector <std::pair <int, int> > hr;

int main () {
  int n, r; scanf ("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) {
    int a; scanf ("%d", &a);
    h.push_back (a);
    if (a) {
      //printf ("%d.st: %d, %d.nd: %d\n", i, i - r + 1, i, i + r - 1);
      hr.push_back ({i - r + 1, i + r - 1});
    }
  }

  long long ans = 0;
  int sz = (int)hr.size () - 1;
  for (int i = 1; i < sz; i++) {
    printf ("i.st: %d, i.nd: %d\n", hr [i].first, hr [i].second);
    if (hr [i - 1].second < hr [i].first || hr [i].second < hr [i + 1].first)
      ans++;
  }

  if (sz > 0) {
    if (hr [0].first <= 1 && hr [hr.size () - 1].second >= n)
      printf ("%lld\n", ans + 2);
    else
      puts ("-1");
  }
  else
    puts ("-1");
  return 0;
}
