#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;
  int count = 0;
  for (int i = 1; i < str.size (); i++) {
    if (str[i] == str[i - 1])
      count++;
    else
      count = 0;
    if (count == 6) {
      puts ("YES");
      return 0;
    }
  }
  puts ("NO");
  return 0;
}
