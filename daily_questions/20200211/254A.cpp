#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 6e5 + 1;

int n;
int arr [MAXN];

void input () {
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);

  scanf ("%d", &n);

  for (int i = 0; i < 2 * n; i++)
    scanf ("%d", arr + i);

  solve ();
}

void solve () {
  std::map <int, std::vector <int> > map;

  for (int i = 0; i < 2 * n; i++)
    map [arr [i]].push_back (i);

  int flag = 1;

  for (auto i = map.begin (); i != map.end (); i++)
    if (i->second.size () % 2)
      flag = 0;

  if (flag)
    for (auto i = map.begin (); i != map.end (); i++)
      for (int j = 0; j < i->second.size (); j += 2)
        printf ("%d %d\n", i->second [j] + 1, i->second [j + 1] + 1);
  else
    puts ("-1");
}

int main () {
  input ();
  return 0;
}
