#include <bits/stdc++.h>

const int MAXN = 2e5 + 1;

std::map <int, int> map;
std::map <int, int> ans;
std::vector < std::pair <int, int> > v;

int arr [MAXN];

int main () {
  int n, k; scanf ("%d%d", &n, &k);

  for (int i = 0; i < n; i++) {
    scanf ("%d", arr + i);
    map [arr [i]]++;
  }

  for (auto i = map.begin (); i != map.end (); i++)
    v.push_back ({i->second, i->first});

  std::sort (v.begin (), v.end ());

  for (int i = 0; i < v.size (); i++) {
    printf ("%d ", v [i].second);
  }
  puts ("");

  //printf ("v.sz: %d, v.sz - k: %d\n", 

  ans[v [v.size () - 1].second]++;
  int count = 1;
  for (int i = ((int)v.size () - 1); i > 0 && count < k; i--) {
    printf ("i: %d, count: %d\n", i, count);
    if ((v [i].second / (ans[(v [i].second)] + 1)) >= v [i - 1].second) {
      ans[(v [i].second)]++;
      i++;
      count++;
    }
    printf ("i: %d, count: %d\n", i, count);
  }

  for (auto i = ans.begin (); i != ans.end (); i++)
    printf ("{%d %d}", i->first, i->second);
  puts ("");

  return 0;
}
