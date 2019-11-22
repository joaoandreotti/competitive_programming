#include <bits/stdc++.h>

std::map <int, int> map;
std::vector <std::pair <int, std::pair <int, int> > > v;

int main () {
  int n; scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    map [a]++;
  }


  // 1 2 4
  // 1 2 6
  // 1 3 6
  int min;
  min = std::min (map [1], std::min (map [2], map [4]));
  for (int i = 0; i < min; i++)
    v.push_back ({1, {2, 4}});
  map [1] -= min;
  map [2] -= min;
  map [4] -= min;

  min = std::min (map [1], std::min (map [2], map [6]));
  for (int i = 0; i < min; i++)
    v.push_back ({1, {2, 6}});
  map [1] -= min;
  map [2] -= min;
  map [6] -= min;

  min = std::min (map [1], std::min (map [3], map [6]));
  for (int i = 0; i < min; i++)
    v.push_back ({1, {3, 6}});
  map [1] -= min;
  map [3] -= min;
  map [6] -= min;

  if (v.size () == n / 3)
    for (int i = 0; i < v.size (); i++)
      printf ("%d %d %d\n", v[i].first, v[i].second.first, v[i].second.second);
  else
    puts ("-1");


  return 0;
}
