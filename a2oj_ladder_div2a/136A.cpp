#include <bits/stdc++.h>

std::vector <std::pair <int, int> > v;

int main () {
  int n; scanf ("%d", &n);

  for (int i = 1; i <= n; i++) {
    int a;
    scanf ("%d", &a);
    v.push_back ({a, i});
  }

  std::sort (v.begin (), v.end ());

  for (int i = 0; i < v.size (); i++)
    printf ("%d ", v [i].second);

  puts ("");
  
  return 0;
}
