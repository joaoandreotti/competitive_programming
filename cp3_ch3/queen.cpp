#include <bits/stdc++.h>

const int MAXN = 8; // board size

// X == column | Y == row
// row [X] stores which row the queen is placed in the column X
int row [MAXN], lc, x, y;

bool check (int r, int c) {
  // for until column == check placed queens
  for (int i = 0; i < c; i++) {
    // if no two queens are in the same row
    // && no two queens share the same diagonal
    if (row [i] == r || (abs (c - i)) == (abs (r - row [i])))
      return false;
  }
  return true;
}

void backtrack (int column = 0) {
  if (column == MAXN && row [x] == y) {
    // all the queens are place == possible solution
    printf ("%2d      ", lc++);
    for (int i = 0; i < MAXN; i++) {
      if (i + 1 < MAXN)
        printf ("%d ", row [i] + 1);
      else
        printf ("%d\n", row [i] + 1);
    }
  }
  // which row from the column X the queen will be place
  for (int i = 0; i < MAXN; i++) {
    if (check (i, column)) {
      row [column] = i;
      // advance a column and calls the recursion
      backtrack (column + 1);
    }
  }
}

int main () {

  int n; scanf ("%d", &n);

  while (n--) {
    scanf ("%d%d", &x, &y);
    std::swap (x, y);
    x--; y--;

    memset (row, 0, sizeof (row));
    puts ("SOLN       COLUMN");
    puts (" #      1 2 3 4 5 6 7 8\n");

    lc = 1;
    backtrack ();
    
    if (n)
      puts ("");
  }


  return 0;
}
