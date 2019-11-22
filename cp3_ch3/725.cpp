#include <bits/stdc++.h>

int main () {
  int n;


  int count = 0;
  while (scanf ("%d", &n) && n != 0) {
    int onei = 0;
    if (count++ > 0)
      puts ("");
    for (int i = 1234; i <= (98765 / n); i++) {
      int a = i * n; // 'a' cant be bigger than 98765

      int tmp;
      int flag = (i < 10000); // if flag than 0WXYZ
      // flag is a bitset to 'set' to numers that are used
      tmp = a;
      while (tmp) {
        flag |= 1 << (tmp % 10);
        tmp /= 10;
      }
      tmp = i;
      while (tmp) {
        flag |= 1 << (tmp % 10);
        tmp /= 10;
      }
      if (flag == (1 << 10) - 1) { // if all bits are 'set'
        printf ("%.5d / %.5d = %d\n", a, i, n);
        onei = 1;
      }
    }
    if (!onei)
      printf ("There are no solutions for %d.\n", n);
  }

  return 0;
}
