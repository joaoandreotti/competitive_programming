#include <bits/stdc++.h>

const int MAXN = 1e2 + 1, INF = 0x3f3f3f3f;

int n;
int arr [MAXN][MAXN];

void input ();
void sol ();

long long cs () {
  long long ans = 0;
  // the 4 initial fors generate all the possibilities
  // to form a rectangle using only the initial point (i, j) and
  // (k, l), then just iterate from (i, j) to (k, l)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = i; k < n; k++) {
        for (int l = j; l < n; l++) {
          printf ("i: %d, j: %d, k: %d, l: %d\n", i, j, k, l);
          long long part = 0;
          // (i, j) to (k, l)
          for (int a = i; a <= k; a++)
            for (int b = j; b <= l; b++) {
              printf ("{%d, %d}\n", a, b);
              part += arr [a][b];
            }
          ans = std::max (ans, part);
          puts ("---------");
        }
      }
    }
  }
  return ans;
}

long long dp () {
  // first we need to transform the input
  // on a commutative sum matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i) arr [i][j] += arr [i - 1][j];
      if (j) arr [i][j] += arr [i][j - 1];
      // remove the double count if has any
      if (i && j) arr [i][j] -= arr [i - 1][j - 1];
    }
  }

  // now we need to only generate all possible
  // rectangles
  long long part = 0, ans = -INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = i; k < n; k++) {
        for (int l = j; l < n; l++) {
          part = arr [k][l]; // (0, 0) to (k, l);
          if (i) part -= arr [i - 1][l];
          if (j) part -= arr [k][j - 1];
          // remove the double count if has any
          if (i && j) part += arr [i - 1][j - 1];
          ans = std::max (ans, part);
        }
      }
    }
  }
  return ans;
}

void input () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf ("%d", arr [i] + j);
}

void sol () {
  printf ("%lld\n", dp ());
}


int main () {
  input ();
  sol ();
  return 0;
}
