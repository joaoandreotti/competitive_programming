#include <bits/stdc++.h>

int main () {
  int n;
  long long x = 0;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    std::string str;
    std::cin >> str;
    if (str.find ('+') < str.size ())
      x++;
    else
      x--;
  }
  printf ("%lld\n", x);
  return 0;
}
