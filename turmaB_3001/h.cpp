#include <bits/stdc++.h>

const int mov_x [4] = {1, -1, 0, 0}, mov_y [4] = {0, 0, 1, -1};
const int MAXN = 1e3 + 1;

int n, m;
char lab [MAXN][MAXN];
int dp [MAXN][MAXN];

int check (int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m && lab [x][y] != '#')
    return 1;

  return 0;
}

int dfs (int x, int y) {
  if (dp [x][y])
    return dp [x][y];

  printf ("dp [%d][%d]: %d\n", x, y, dp [x][y]);
  lab [x][y] = '#';
  for (int i = 0; i < 4; i++) {
    if (check (x + mov_x [i], y + mov_y [i])) {
      dp [x][y] = std::max (dfs (x + mov_x [i], y + mov_y [i]) + 1, dp [x][y]);
    }
  }
  lab [x][y] = '.';
  printf ("dp [%d][%d]: %d\n", x, y, dp [x][y]);

  return dp [x][y];
}

int f (int x, int y) {
  for (int i = 0; i < 4; i++) {
    if (check (x + mov_x [i], y + mov_y [i])) {
      dp [x][y] = std::max (dfs (x + mov_x [i], y + mov_y [i]) + 1, dp [x][y]);
    }
  }
}

int main () {
  int T; scanf ("%d", &T);

  while (T--) {
    scanf ("%d%d", &m, &n);

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)  {
      for (int j = 0; j < m; j++) {
        scanf (" %c", &lab [i][j]);
        //printf ("%c", lab [i][j]);
        dp [i][j] = 0;
      }
      //puts ("");
    }

    puts ("dfs:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (lab [i][j] != '#') {
          printf ("i: %d, j: %d\n", i, j);
          dfs (i, j);
        }
      }
    }
    puts ("----");


    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ans = std::max (dp [i][j], ans);

    printf ("Maximum rope length is %d.\n", ans);

  }
  return 0;
}
