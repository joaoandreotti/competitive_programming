#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 4e3 + 10;

int n;
int arr [3];
int dp [MAXN][3];

int coin (int x, int p) {
  if (dp [x][p])
    return dp [x][p];
  if (p >= 3 && x)
    return -INT_MAX;
  if (p >= 3 || !x)
    return 0;

  if (x - arr [p] >= 0)
    return dp [x][p] = std::max (coin (x - arr [p], p) + 1, coin (x, p + 1));
  else
    return dp [x][p] = coin (x, p + 1);
}

void input () {
  scanf ("%d%d%d%d", &n, arr, arr + 1, arr + 2);
  solve ();
}

void solve () {
  printf ("%d\n", coin (n, 0));
}

int main () {
  input ();
  return 0;
}
