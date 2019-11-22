#include <bits/stdc++.h>

const int MAXN = 15; // board size

// X == column | Y == row
// row [X] stores which row the queen is placed in the column X
int row [MAXN], lc, x, y;
int blkd [MAXN];
int n;

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

bool check_blkd (int r, int c) {
  for (int i = 0; i < n; i++) {
    //printf ("blkd [%d]: %d, {%d, %d}\n", i, blkd [i], c, r);
    if (blkd [i] == r && i == c) {
      return false;
    }
  }
  return true;
}

int counter = 0;
void backtrack (int column = 0) {
  if (column == n) {
    // all the queens are placed == possible solution
    /*
    for (int i = 0; i < n; i++) {
      printf ("{%d, %d} ", i, row [i]);
    }
    puts ("");
    */
    lc++;
    return;
  }
  // which row from the column X the queen will be place
  for (int r = 0; r < n; r++) {
    if (check (r, column) && check_blkd (r, column)) {
      row [column] = r;
      // advance a column and calls the recursion
      backtrack (column + 1);
    }
  }
}

int main () {
  int t = 1;

  while (scanf ("%d", &n) && n) {
    memset (row, 0, sizeof (row));
    memset (blkd, -1, sizeof (blkd));
    std::string str;
    for (int i = 0; i < n; i++) {
      std::cin >> str;
      //std::cout << "str: " << str << '\n';
      for (int j = 0; j < n; j++) {
        if (str [j] == '*') {
          blkd [j] = i;
        }
      }
    }
    /*
    puts ("BLKD:");
    for (int i = 0; i < n; i++)
      printf ("%d ", blkd [i]);
    puts ("");
    */
    lc = 0;
    backtrack ();
    printf ("Case %d: %d\n", t++, lc);
  }


  return 0;
}
