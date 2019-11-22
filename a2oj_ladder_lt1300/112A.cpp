#include <bits/stdc++.h>

int main () {
  std::string f, s;
  std::cin >> f >> s;

  std::transform (f.begin (), f.end (), f.begin (), ::tolower);
  std::transform (s.begin (), s.end (), s.begin (), ::tolower);

  for (int i = 0; i < f.size (); i++)
    if (f[i] < s[i]) {
      puts ("-1");
      return 0;
    }
    else if (f[i] > s[i]) {
      puts ("1");
      return 0;
    }

  puts ("0");
  return 0;
}
