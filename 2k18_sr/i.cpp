#include <bits/stdc++.h>

std::map <int, std::vector <int> > map;
std::set <int> init, on, off;

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);

  int l;
  scanf ("%d", &l);
  for (int i = 0; i < l; i++) {
    int a;
    scanf ("%d", &a);
    on.insert (a);
  }
  init = on;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf ("%d", &a);
    for (int j = 0; j < a; j++) {
      scanf ("%d", &b);
      map[i].push_back (b);
    }
  }

  long long ans = 0;
  while (true) {
    for (auto i = map.begin (); i != map.end (); i++) {
      for (int j = 0; j < i->second.size (); j++) {
        if (on.find (i->second[j]) != on.end ()) {
          on.erase (i->second[j]);
          off.insert (i->second[j]);
        }
        else {
          on.insert (i->second[j]);
          off.erase (i->second[j]);
        }
      }
      ans++;
      if (on.size () == 0) {
        printf ("%lld\n", ans);
        return 0;
      }
    }
    if (on == init) {
      printf ("-1\n");
      return 0;
    }
  }
  return 0;
}
