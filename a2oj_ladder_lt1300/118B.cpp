#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);

  int chrs = 1, count = 0, spc = n * 2;
  for (int i = 1; i <= (n + 1); i++) {
    for (int j = 0; j < spc;j++)
      printf (" ");

    for (int j = 0; j <= count; j++)
      if (j + 1 <= count)
        printf ("%d ", j);
      else
        printf ("%d", j);
    if (count > 0) {
      printf (" ");
      for (int j = count - 1; j >= 0; j--)
        if (j - 1 >= 0)
          printf ("%d ", j);
        else
          printf ("%d\n", j);
    }
    else
      puts ("");
    count++;
    spc -= 2;
    chrs += 2;
  }
  chrs = (2 * n) - 1;
  spc = 2;
  count -= 2;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < spc;j++)
      printf (" ");

    for (int j = 0; j <= count; j++)
      if (j + 1 <= count)
        printf ("%d ", j);
      else
        printf ("%d", j);
    if (count > 0) {
      printf (" ");
      for (int j = count - 1; j >= 0; j--)
        if (j - 1 >= 0)
          printf ("%d ", j);
        else
          printf ("%d\n", j);
    }
    else
      puts ("");
    count--;
    spc += 2;
    chrs -= 2;
  }
  return 0;
}
