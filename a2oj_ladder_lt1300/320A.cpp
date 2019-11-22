#include <bits/stdc++.h>

int main () {
  std::string a;
  std::cin >> a;
  for (int i = 0; i < a.size (); i++) {
    if (a.substr (i, 3) == "144") {
      i += 2;
    }
    else if (a.substr (i, 2) == "14") {
      i += 1;
    }
    else if (a.substr (i, 1) == "1") {
      continue;
    }
    else {
      puts ("NO");
      return 0;
    }
  }
  puts ("YES");
  return 0;
}
