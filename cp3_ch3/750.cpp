#include <bits/stdc++.h>

int x, y;
int row [8], lineC;

bool place (int i, int j) {
  for (int p = 0; p < j; p++) {
    if (row [p] == i || (abs (row [p] - i)) == (abs (p - j)))
      return 0;
  }
  return 1;
}


void bt (int c) {
  if (c == 8 && row [x] == y) {
    printf ("%d    %d", ++lineC, row[0] + 1);
    for (int j = 1; j < 8; j++)
      printf (" %d", row [j] + 1);
    puts ("");
  }
  for (int i = 0; i < 8; i++) {
    if (place (i, c)) {
      row [c] = i;
      bt (c + 1);
    }
  }
}

int main () {
  int t; scanf ("%d", &t);

  while (t--) {
     scanf ("%d%d", &x, &y);
     x--; y--;
     memset (row, 0, sizeof (row));
     lineC = 0;
     bt (0);
  }
  return 0;
}
