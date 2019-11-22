#include <bits/stdc++.h>

std::map <int, std::vector <int> > map;
std::vector <std::pair <int, int> > res;

int main () {
  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    map [a].push_back (i + 1);
  }

  for (auto i = map.begin (); i != map.end (); i++)
    std::sort (i->second.begin (), i->second.end ());

  for (auto i = map.begin (); i != map.end (); i++) {
    char flag = 0;
    //printf ("st: %d, sz: %d\n", i->first, i->second.size ());
    if (i->second.size () == 1)
      res.push_back ({i->first, 0});
    else if (i->second.size () == 2)
      res.push_back ({i->first, i->second [1] - i->second [0]});
    else {
      int r = i->second [1] - i->second [0];
      for (int j = 1; j < (i->second.size () - 1); j++) {
        //printf ("radius: %d\n", (i->second [j + 1] - i->second [j]));
        if ((i->second [j + 1] - i->second [j]) != r)
          flag = 1;
      }
      if (!flag)
        res.push_back ({i->first, r});
    }
  }

  printf ("%d\n", res.size ());
  for (int i = 0; i < res.size (); i++)
    printf ("%d %d\n", res[i].first, res[i].second);

  return 0;
}
