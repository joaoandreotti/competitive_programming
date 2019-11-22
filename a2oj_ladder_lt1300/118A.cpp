#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;
  std::transform (str.begin (), str.end (), str.begin (), ::tolower);
  for (int i = 0; i < str.size (); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y') {
      str.replace (i, 1, std::string (""));
      i--;
    }
    else if (str[i] != '.') {
      str.replace (i, 1, std::string (".") + std::string (1, str[i]));
      i++;
    }
  }
  std::cout << str << '\n';
  return 0;
}
