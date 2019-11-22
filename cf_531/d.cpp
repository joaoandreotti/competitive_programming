#include <bits/stdc++.h>

int main () {
  int n; std::cin >> n;
  std::string str;
  std::cin >> str;


  int z = 0, o = 0, t = 0;
  for (int i = 0; i < str.size (); i++) {
    if (str [i] == '0')
      z++;
    if (str [i] == '1')
      o++;
    if (str [i] == '2')
      t++;
  }

  if (t < (n / 3)) {
    //puts ("c");
    for (int i = str.size () - 1; i >= 0 && t < (n / 3); i--) {
      if (str [i] == '1' && o > (n / 3)) {
        t++;
        o--;
        str [i] = '2';
      }
      else if (str [i] == '0' && z > (n / 3)) {
        t++;
        z--;
        str [i] = '2';
      }
    }
    //std::cout << str << std::endl;
  }
  if (z < (n / 3)) {
    //puts ("a");
    for (int i = 0; i < str.size () && z < (n / 3); i++) {
      if (str [i] == '2' && t > (n / 3)) {
        z++;
        t--;
        str [i] = '0';
      }
    }
    for (int i = 0; i < str.size () && z < (n / 3); i++) {
      if (str [i] == '1' && o > (n / 3)) {
        z++;
        o--;
        str [i] = '0';
      }
    }
    //std::cout << str << std::endl;

  }
  if (o < (n / 3)) {
    //puts ("b");
    for (int i = 0; i < str.size () && o < (n / 3); i++) {
      if (str [i] == '2' && t > (n / 3)) {
        o++;
        t--;
        str [i] = '1';
      }
    }
    for (int i = str.size (); i >= 0 && o < (n / 3); i--) {
      if (str [i] == '0' && z > (n / 3)) {
        o++;
        z--;
        str [i] = '1';
      }
    }
    //std::cout << str << std::endl;
  }

  std::cout << str << std::endl;

  return 0;
}
