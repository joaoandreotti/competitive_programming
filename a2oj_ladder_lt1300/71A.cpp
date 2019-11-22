#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    std::string str;
    std::cin >> str;
    if (str.size () <= 10)
      std::cout << str << '\n';
    else
      std::cout << str[0] << str.size () - 2 << str[str.size () - 1] << '\n';
  }
  return 0;
}
