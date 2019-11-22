#include <bits/stdc++.h>

std::map <char, int> map;

int main () {
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size (); i++)
    map [str [i]]++;

  if (str.size () % 2) {
    puts ("First");
  }
  else {
    int count = 0;
    for (auto i = map.begin (); i != map.end (); i++)
      if (i->second % 2)
        count++;
    if (!count)
      puts ("First");
    else
      puts ("Second");
  }
  return 0;
}
