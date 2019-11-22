#include <bits/stdc++.h>

std::map <std::string, int> map;

int main () {
  int n;
  scanf ("%d", &n);
  std::string str;
  for (int i = 0; i < n; i++) {
    std::cin >> str;
    map[str]++;
  }
  auto i = map.begin ();
  auto j = ++i;
  i = map.begin ();
  if (i->second > j->second)
    std::cout << i->first << '\n';
  else
    std::cout << j->first << '\n';
  return 0;
}
