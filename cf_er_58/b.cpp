#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;

  int flag = 0;
  int lastB;
  int firstC = 0, lastC = 0;
  for (int i = 0; i < str.size (); i++) {
    if (str [i] == '[' && flag == 0)
      flag = 1;
    else if (str [i] == ':' && flag == 1) {
      firstC = i;
      flag = 2;
    }
    else if (str [i] == ':' && flag == 2)
      flag = 3;
    else if (str [i] == ']' && flag == 3) {
      flag = 4;
    }

    if (str [i] == ']')
      lastB = i;

    //printf ("flag: %d\n", flag);
  }

  if (flag == 4) {
    int ans = 4;

    for (int i = lastB; i > firstC; i--) {
      if (str [i] == ':') {
        lastC = i;
        break;
      }
    }

    for (int i = firstC; i < lastC; i++)
      if (str [i] == '|')
        ans++;
    printf ("%d\n", ans);

  }
  else
    puts ("-1");
  return 0;
}
