#include <bits/stdc++.h>

std::set <char> set;

int main () {
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size (); i++)
    set.insert (str[i]);

  if (set.size () % 2 == 0)
    puts ("CHAT WITH HER!");
  else
    puts ("IGNORE HIM!");
  return 0;
}
