#include <bits/stdc++.h>

std::map <char, int> map;

int main () {
  int k;
  scanf ("%d", &k);
  std::string str;
  std::cin >> str;
  if (k == 1)
    std::cout << str << '\n';
  else {
    for (int i = 0; i < str.size (); i++)
      map [str[i]]++;

    for (auto i = map.begin (); i != map.end (); i++)
      if (i->second % k != 0) {
        puts ("-1");
        return 0;
      }

    std::string ans = "";
    for (int j = 0; j < k; j++)
      for (auto i = map.begin (); i != map.end (); i++)
        for (int l = 0; l < i->second / k; l++)
          ans += i->first;
    std::cout << ans << '\n';
  }
  return 0;
}
