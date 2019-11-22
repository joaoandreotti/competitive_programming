#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size (); i++) {
    if (str[i] == '.')
      printf ("0");
    if (str[i] == '-') {
      if (str[i + 1] == '.')
        printf ("1");
      else
        printf ("2");
      i++;
    }
  }
  puts ("");
  return 0;
}
