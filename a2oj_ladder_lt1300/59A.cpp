#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;

  int lc = 0, uc = 0;
  for (int i = 0; i < str.size (); i++)
    if (str[i] >= 'a' && str[i] <= 'z')
      lc++;
    else
      uc++;

  if (lc >= uc)
    std::transform (str.begin (), str.end (), str.begin (), ::tolower);
  else
    std::transform (str.begin (), str.end (), str.begin (), ::toupper);

  std::cout << str << '\n';
  return 0;
}
