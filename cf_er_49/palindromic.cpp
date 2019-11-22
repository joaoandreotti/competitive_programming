#include <stdio.h>
#include <string>
#include <iostream>
//#include <bits/stdc++.h>

int main () {
  int x, n;
  std::string name;
  scanf ("%d", &x);

  for (int c = 0; c < x; c++) {
    int flag = 0;
    std::cin >> n >> name;

    int i = 0, j = n - 1;
    while (i != (n/2)) {
      //printf ("%d : %c | %c\n", abs((int)name [i] - (int)name [i + (n/2)]), name[i], name [i + (n/2)]);
      if (abs(name [i] - name [j]) != 2 && abs(name [i] - name [j]) != 0) {
        printf ("NO\n");
        flag = 1;
        break;
      }
      i++;
      j--;
    }
    if (!flag) {
      printf ("YES\n");
    }
  }
  return 0;
}
