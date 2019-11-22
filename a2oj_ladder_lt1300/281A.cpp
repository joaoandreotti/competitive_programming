#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;
  if (!(str[0] >= 'A' && str[0] <= 'Z'))
    str[0] = str[0] - ('a' - 'A');
  std::cout << str << '\n';
  return 0;
}
