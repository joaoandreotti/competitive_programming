#include <bits/stdc++.h>

int get_dig (int dig, int a) {
  a /= pow (10, dig);
  return a % 10;
}

bool f (int a) {
  if (a == 0 || a == 1)
    return 0;
  //printf ("log10(%d): %lf, ceil (log10(%d)): %d\n", a, log10(a), a, ceil (log10(a)));
  for (int i = 0; i < ceil (log10(a)); i++) {
    if (get_dig (i, a) == 7 || get_dig (i, a) == 4)
      continue;
    else
      return 0;
  }
  return 1;
}

int main () {
  int ans = 0;
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size (); i++)
    if (str[i] == '4' || str[i] == '7')
      ans++;

  //printf ("ANS: %d\n", ans);
  if (f (ans))
    printf ("YES\n");
  else
    printf ("NO\n");


  return 0;
}
