#include <bits/stdc++.h>

int main () {
  int perm [5], n = 5;

  for (int i = 0; i < n; i++)
    perm [i] = i;

  for (int i = 0; i < (1 << n); i++) {
    //printf ("i: %d\n", i);
    for (int j = 0; j < n; j++) {
      //printf ("i: %d, (1 << %d): %d -- ", i, j, (1 << j));
      if (i & (1 << j))
        printf ("%d", perm [j]);

      //puts ("");
    }

    puts ("");
  }
  return 0;
}
