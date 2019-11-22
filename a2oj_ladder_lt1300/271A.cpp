#include <bits/stdc++.h>

int get_dig (int dig, int a) {
  a /= pow (10, dig);
  return a % 10;
}

bool f (int a) {
  std::set <int> dig;
  for (int i = 0; i < log10(a); i++) {
    //printf ("Dig: %d\n", get_dig (i, a));
    if (dig.find (get_dig (i, a)) == dig.end ())
      dig.insert (get_dig (i, a));
    else
      return 0;
  }
  return 1;
}

int main () {
  int n;
  scanf ("%d", &n);

  for (int i = n + 1;;i++) {
    //printf ("i: %d\n", i);
    if (f (i)) {
      printf ("%d\n", i);
      return 0;
    }
  }
  return 0;
}
