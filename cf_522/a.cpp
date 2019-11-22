#include <bits/stdc++.h>

std::map <int, int> map;
int main () {
  int n, k; scanf ("%d%d", &n, &k);
  int a;
  for (int i = 0; i < n; i++) {
    scanf ("%d", &a);
    map [a]++;
  }

  int max = 0;
  for (auto i = map.begin (); i != map.end (); i++)
    if (i->second % k == 0 && (i->second / k) >= max)
      max = (i->second / k);
    else if (i->second % k && ((i->second / k) + 1) >= max)
      max = (i->second / k) + 1;

  long long ans = 0;
  for (auto i = map.begin (); i != map.end (); i++)
    ans += (max * k) - i->second;

  printf ("%lld\n", ans);
  return 0;
}
