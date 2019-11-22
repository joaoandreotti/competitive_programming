#include <bits/stdc++.h>

std::multiset <int> l, r;
std::vector <std::pair <int, int> > vpii;

int main () {
  int n, x, y;
  scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf ("%d%d", &x, &y);
    l.insert (x);
    r.insert (y);
    vpii.push_back ({x, y});
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    l.erase (l.find (vpii[i].first));
    r.erase (r.find (vpii[i].second));
    //std::cout << vpii[i].first << " | " << vpii[i].second << "; " << *(r.begin ()) << " : " << *(--l.end ()) << '\n';
    ans = std::max (ans, *(r.begin ()) - *(--l.end ()));
    l.insert (vpii[i].first);
    r.insert (vpii[i].second);
  }

  std::cout << ans << '\n';
  return 0;
}
