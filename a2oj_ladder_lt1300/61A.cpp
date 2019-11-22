#include <bits/stdc++.h>

int main () {
  std::string a, b;
  std::cin >> a >> b;

  std::bitset <100> bt1 (a);
  std::bitset <100> bt2 (b);
  std::bitset <100> ans;
  ans = (bt1 ^ bt2);
  for (int i = a.size () - 1; i >= 0; i--)
    std::cout << ans[i];
  puts ("");
  return 0;
}
