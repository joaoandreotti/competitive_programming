#include <bits/stdc++.h>

void input ();
void solve ();

int n;
std::map <std::pair <int, int>, int> map;

void input () {
  scanf ("%d", &n);
  for (int i = 0, a, b; i < n && scanf ("%d%d", &a, &b); i++)
    map [{a, b}]++;

  solve ();
}

void solve () {
  int ans = 0;
  for (auto i = map.begin (); i != map.end (); i++)
    ans = std::max (ans, i->second);

  printf ("%d\n", ans);
}

int main () {
  input ();
  return 0;
}
