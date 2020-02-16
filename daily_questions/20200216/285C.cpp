#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 3e5 + 1;

int n;
std::map <int, int> map;
std::set <int> set;

void input () {
  scanf ("%d", &n);

  for (int i = 0, a; i < n && scanf ("%d", &a); i++) {
    map [a]++;
    set.insert (i + 1);
  }

  solve ();
}

void solve () {
  for (auto i = map.begin (); i != map.end (); i++)
    if (set.find (i->first) != set.end ()) {
      i->second--;
      set.erase (i->first);
    }

  long long ans = 0;
  for (auto i = map.begin (); i != map.end (); i++) {


    //printf ("i->first: %d\n", i->first);
    while (i->second) {
      /*
      for (auto j = set.begin (); j != set.end (); j++)
        printf ("{%d}", *j);
      puts ("");
      */
      int aux = *set.begin ();
      ans += labs (i->first - aux);
      //printf ("abs: %d\n", labs (i->first - aux));
      set.erase (set.begin ());
      i->second--;
    }
  }

  printf ("%lld\n", ans);

}

int main () {
  input ();
  return 0;
}
