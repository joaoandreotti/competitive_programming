#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e3 + 1;

int movx [4] = {1, -1, 0, 0};
int movy [4] = {0, 0, 1, -1};

int n;
int path [MAXN][MAXN];
int vis [MAXN][MAXN];
int flag;

void dfs (int i, int j) {
  vis [i][j] = 1;

  if (i == n - 1 && j == n - 1)
    flag = 1;

  for (int k = 0; k < 4; k++) {
    if ((movx [k] + i) >= 0 && (movx [k] + i) < n)
      if ((movy [k] + j) >= 0 && (movy [k] + j) < n)
        if (!vis [movx [k] + i][movy [k] + j])
          if (path [movx [k] + i][movy [k] + j])
            dfs (movx [k] + i, movy [k] + j);
  }
}

void input () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf ("%d", path [i] + j);

  solve ();
}

void solve () {
  flag = 0;

  dfs (0, 0);

  if (flag)
    puts ("Vai pra aula, Dilsinho!");
  else
    puts ("Fica em casa, Dilsinho!");
}

int main () {
  input ();
  return 0;
}
