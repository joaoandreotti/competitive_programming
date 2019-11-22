#include <bits/stdc++.h>

std::map <char, int> map, tm;
std::vector <std::pair <int, char> > vector;

int main () {
  int n, k;
  scanf ("%d%d", &n, &k);
  char a;
  for (int i = 0; i < n; i++) {
    scanf ("\n%c", &a);
    map [a]++;
  }
  for (auto i = map.begin (); i != map.end (); i++)
    vector.push_back ({i->second, i->first});

  std::sort (vector.begin (), vector.end ());

  for (int i = vector.size () - 1; i >= 0; i--) {
    if (k - vector[i].first >= 0) {
      k -= vector[i].first;
      tm[vector[i].second] = vector[i].first;
    }
    else if (k > 0) {
      tm[vector[i].second] = k;
      k = 0;
    }

    //printf ("k: %d, card: %c, value: %d\n", k, vector[i].second, tm[vector[i].second]);
  }

  long long ans = 0;
  for (auto i = tm.begin (); i != tm.end (); i++) {
    //printf ("card: %c, value: %d\n", i->first, i->second);
    ans += (long long)pow (i->second, 2);
  }

  printf ("%lld\n", ans);

  return 0;
}
