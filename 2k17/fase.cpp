#include <bits/stdc++.h>

std::map <int, int> map;

int main() {
  int n, k;
  scanf ("%d%d", &n, &k);

  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    map[a]++;
  }
  int ans = 0;
  for (auto i = map.rbegin (); i != map.rend (); i++)
    if (ans < k)
      ans += i->second;

  printf ("%d\n", ans);
  return 0;
}
