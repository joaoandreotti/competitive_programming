#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;

  int flag = 0;
  for (int i = 0; i < str.size (); i++)
    if (str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
      flag = 1;

  if (flag)
    puts ("YES");
  else
    puts ("NO");
  return 0;
}
