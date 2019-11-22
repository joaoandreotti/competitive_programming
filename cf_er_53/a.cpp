#include <bits/stdc++.h>

int main () {
  int n;
  std::string str, sub;
  std::cin >> n >> str;

  

  for (int i = 0; i < n; i += 2) {
    if ((i + 1 < n) && (str [i] != str [i + 1])) {
      sub = str [i];
      sub +=  str [i + 1];
    }
  }

  if (sub.size ())
    std::cout << "YES\n" << sub << '\n';
  else
    puts ("NO");

  return 0;
}
