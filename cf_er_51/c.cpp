#include <bits/stdc++.h>

std::vector <int> vector;
std::map <int, int> map;
std::set <int> set, set_2, sa, sb;

int main () {
  int n;
  scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    vector.push_back (a);
    map[a]++;
  }

  long long nice = 0;
  for (auto i = map.begin (); i != map.end (); i++) {
    if (i->second == 1) {
      nice++;
      set.insert (i->first);
    }
    else if (i->second % 2 == 1) {
      set_2.insert (i->first);
    }
  }

  if (nice % 2 == 0) {
    printf ("YES\n");
    int t = 0;
    for (auto i = 0; i < vector.size (); i++) {
      if (set.find (vector[i]) != set.end ()) {
        if (t == 0) {
          printf ("A");
          t = 1;
          continue;
        }
        else {
          printf ("B");
          t = 0;
          continue;
        }
      }
      printf ("A");
    }
    printf ("\n");
  }
  else if (set_2.size () > 0){
    printf ("YES\n");
    int t = 0;
    for (auto i = 0; i < vector.size (); i++) {
      if (set.find (vector[i]) != set.end ()) {
        if (t == 0) {
          printf ("A");
          t = 1;
          continue;
        }
        else {
          printf ("B");
          t = 0;
          continue;
        }
      }
      if (set_2.find (vector[i]) != set_2.end ()) {
        set_2.erase (vector[i]);
        if (t == 0 && sa.find (vector[i]) == sa.end ()) {
          printf ("%d", vector[i]);
          printf ("A");
          t = 1;
          continue;
        }
        else {
          printf ("B");
          t = 0;
          continue;
        }
      }

      printf ("A");
    }
    printf ("\n");
  }
  else {
    printf ("NO\n");
  }

  return 0;
}
