#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;
  char arr [5] = {'h', 'e', 'l', 'l', 'o'};
  int count = 0;
  for (int i = 0; i < str.size (); i++)
    if (str[i] == 'h' && count == 0)
      count++;
    else if (str[i] == 'e' && count == 1)
      count++;
    else if (str[i] == 'l' && count == 2)
      count++;
    else if (str[i] == 'l' && count == 3)
      count++;
    else if (str[i] == 'o' && count == 4)
      count++;

  if (count == 5)
    puts ("YES");
  else
    puts ("NO");

  return 0;
}
