#include <bits/stdc++.h>

int main () {
  std::string str1, str2;
  std::cin >> str1 >> str2;

  if (str1.size () != str2.size ())
    puts ("NO");
  else {
    int pos1 = -1, pos2 = -1, changes = 0;

    for (int i = 0; i < str1.size (); i++) {
      if (str1[i] != str2 [i]) {
        if (pos1 == -1) {
          changes++;
          pos1 = i;
        }
        else if (pos2 == -1) {
          changes++;
          pos2 = i;
        }
      }
    }

    if (changes > 2)
      puts ("NO");
    else {
      std::swap (str1[pos1], str1[pos2]);
      if (str1 == str2)
        puts ("YES");
      else
        puts ("NO");
    }
  }


  return 0;
}
