#include <bits/stdc++.h>


std::set <int> set;
std::map <int, int> map;
//int arr [int (1e5) + 1];

int main () {
  int n, m; scanf ("%d%d", &n, &m);


  int flag = 0;
  for (int i = 0; i < m; i++) {
    int a; scanf ("%d", &a);

    map [a]++;
    set.insert (a);

    if (set.size () == n) {
      printf ("1");
      set.clear ();
      for (auto j = map.begin (); j != map.end (); j++) {
        if (j->second)
          j->second--;

        if (j->second)
          set.insert (j->first);
      }
    }
    else
      printf ("0");
  }

  return 0;
}
