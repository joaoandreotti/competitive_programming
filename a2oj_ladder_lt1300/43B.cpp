#include <bits/stdc++.h>

std::map <char, int> np, msg;

int main () {
  std::string a1, a2;
  getline (std::cin, a1);
  getline (std::cin, a2);

  for (int i = 0; i < a1.size (); i++)
    np[a1[i]]++;
  for (int i = 0; i < a2.size (); i++)
    msg[a2[i]]++;

  for (auto i = msg.begin (); i != msg.end (); i++)
    if (i->first != ' ' && i->second > np [i->first]) { 
      puts ("NO");
      return 0;
    }
  puts ("YES");
  return 0;
}
