#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e2 + 1;

int n, arr [MAXN];

void input () {
  scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  solve ();
}

void solve () {
  std::map <int, int> map;

  for (int i = 0; i < n; i++)
    map [arr [i]]++;

  for (auto i = map.begin (); i != map.end (); i++)
    if (i->second > ((n / 2) + (n % 2))) {
      puts ("NO");
      return;
    }

  puts ("YES");
}

int main () {
  input ();
  return 0;
}
