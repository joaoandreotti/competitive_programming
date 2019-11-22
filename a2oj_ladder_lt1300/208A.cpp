#include <bits/stdc++.h>

int main () {
  std::string str, song;
  std::cin >> str;

  int flag = 0;
  for (int i = 0; i < str.size (); i++) {
    if (i + 2 < str.size () && str.substr (i, 3) == "WUB") {
      i += 2;
    }
    else {
      int j = i;
      while (j < str.size () && str.substr (j, 3) != "WUB") {
        song += str [j++];
      }
      song += ' ';
      i = j - 1;
    }
  }

  std::cout << song << '\n';
  return 0;
}
