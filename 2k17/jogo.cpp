#include <bits/stdc+>

int main () {
  std::string str;
  std::cin >> str;
  int count = 0;
    
  for (int i = 0; i < str.size (); i++)
    count += (str[i] - '0') % 3;

  printf ("%d\n", count % 3);
  return 0;
}
