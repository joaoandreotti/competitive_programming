#include <bits/stdc++.h>

int main () {
  std::string ber, bir;
  std::cin >> ber >> bir;
  std::reverse (bir.begin (), bir.end ());
  if (ber == bir)
    puts ("YES");
  else
    puts ("NO");
  return 0;
}
