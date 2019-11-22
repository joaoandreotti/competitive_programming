#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int lc = 0, uc = 0, num = 0;
    std::string str;
    std::cin >> str;

    for (int j = 0; j < str.size (); j++) {
      if (str[j] >= 'a' && str[j] <= 'z')
        lc++;
      if (str[j] >= 'A' && str[j] <= 'Z')
        uc++;
      if (str[j] >= '0' && str[j] <= '9')
        num++;
    }

    int cp = -1;
    if (!lc) {
      for (int j = 0; j < str.size (); j++) {
        if (str[j] >= 'A' && str[j] <= 'Z' && uc > 1 && cp != j) {
          str [j] = 'a';
          lc++;
          uc--;
          cp = j;
          break;
        }
        if (str[j] >= '0' && str[j] <= '9' && num > 1 && cp != j) {
          str [j] = 'a';
          lc++;
          num--;
          cp = j;
          break;
        }
      }
    }
    if (!uc) {
      for (int j = 0; j < str.size (); j++) {
        if (str[j] >= 'a' && str[j] <= 'z' && lc > 1 && cp != j) {
          str [j] = 'A';
          uc++;
          lc--;
          cp = j;
          break;
        }
        if (str[j] >= '0' && str[j] <= '9' && num > 1 && cp != j) {
          str [j] = 'A';
          uc++;
          num--;
          cp = j;
          break;
        }
      }
    }
    if (!num) {
      for (int j = 0; j < str.size (); j++) {
        if (str[j] >= 'A' && str[j] <= 'Z' && uc > 1 && cp != j) {
          str [j] = '0';
          num++;
          uc--;
          cp = j;
          break;
        }
        if (str[j] >= 'a' && str[j] <= 'z' && lc > 1 && cp != j) {
          str [j] = '0';
          num++;
          lc--;
          cp = j;
          break;
        }
      }
    }

    std::cout << str << '\n';
  }

  return 0;
}
