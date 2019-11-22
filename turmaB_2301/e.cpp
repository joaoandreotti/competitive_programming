#include <bits/stdc++.h>

typedef std::pair <int, int> pi;

char board [8][8];

bool knight (pi king, int flag) {
  for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
      if (((abs (i) + abs (j)) == 3)) {
        if (i + king.first >= 0 && i + king.first < 8) {
          if (j + king.second >= 0 && j + king.second < 8) {
            if (flag && board [i + king.first][j + king.second] == 'n')
              return true;
            if (!flag && board [i + king.first][j + king.second] == 'N')
              return true;
          }
        }
      }
    }
  }
  return false;
}

bool pawn (pi king, int flag) {
  if (flag) {
    int i = king.first - 1, j = king.second - 1;
    if (i >= 0 && i < 8 && j >= 0 && j < 8) {
      if (board [i][j] == 'p')
        return true;
    }
    j += 2;
    if (i >= 0 && i < 8 && j >= 0 && j < 8) {
      if (board [i][j] == 'p')
        return true;
    }
  }
  else {
    int i = king.first + 1, j = king.second - 1;
    if (i >= 0 && i < 8 && j >= 0 && j < 8) {
      if (board [i][j] == 'P')
        return true;
    }
    j += 2;
    if (i >= 0 && i < 8 && j >= 0 && j < 8) {
      if (board [i][j] == 'P')
        return true;
    }
  }
  return false;
}

bool bishop (pi king, char pc) {
  for (int i = king.first - 1, j = king.second - 1; i >= 0 && j >= 0; i--, j--) {
    if (board [i][j] == pc)
      return true;
    else if (board [i][j] != '.')
      break;
  }

  for (int i = king.first - 1, j = king.second + 1; i >= 0 && j < 8; i--, j++) {
    if (board [i][j] == pc)
      return true;
    else if (board [i][j] != '.')
      break;
  }

  for (int i = king.first + 1, j = king.second - 1; i < 8 && j >= 0; i++, j--) {
    if (board [i][j] == pc)
      return true;
    else if (board [i][j] != '.')
      break;
  }

  for (int i = king.first + 1, j = king.second + 1; i < 8 && j < 8; i++, j++) {
    if (board [i][j] == pc)
      return true;
    else if (board [i][j] != '.')
      break;
  }

  return false;
}

bool rook (pi king, char pc) {
  for (int i = king.first + 1; i < 8; i++) {
    if (board [i][king.second] == pc)
      return true;
    else if (board [i][king.second] != '.')
      break;
  }

  for (int i = king.first - 1; i >= 0; i--) {
    if (board [i][king.second] == pc)
      return true;
    else if (board [i][king.second] != '.')
      break;
  }

  for (int j = king.second + 1; j < 8; j++) {
    if (board [king.first][j] == pc)
      return true;
    else if (board [king.first][j] != '.')
      break;
  }

  for (int j = king.second - 1; j >= 0; j--) {
    if (board [king.first][j] == pc)
      return true;
    else if (board [king.first][j] != '.')
      break;
  }

  return false;

}

int main () {
  int cs = 0;

  while (++cs) {
    pi blkK = {8, 8}, whtK = {8, 8};
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        scanf (" %c", &board[i][j]);
        if (board [i][j] == 'k')
          blkK = {i, j};
        else if (board [i][j] == 'K')
          whtK = {i, j};
      }
    }
    if (blkK == whtK)
      break;

    printf ("Game #%d: ", cs);
    if (knight (blkK, 0) || pawn (blkK, 0) || bishop (blkK, 'B') || bishop (blkK, 'Q') || rook (blkK, 'R') || rook (blkK, 'Q'))
      puts ("black king is in check.");
    else if (knight (whtK, 1) || pawn (whtK, 1) || bishop (whtK, 'b') || bishop (whtK, 'q') || rook (whtK, 'r') || rook (whtK, 'q'))
      puts ("white king is in check.");
    else
      puts ("no king is in check.");
  }
}
