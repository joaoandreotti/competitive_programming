#include <bits/stdc++.h>

const int MAXN = 1e3 + 1;

int n;
long long arr [MAXN][MAXN], sdws [MAXN][MAXN];

int main () {
  
  while (scanf ("%d", &n) && n != 0) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++)
        scanf ("%lld", arr [i] + j);

    memset (sdws, 0xc0, sizeof sdws);

    for (int i = 0; i < n; i++) {
      int x = i, y = 0;
      while (x < n) {
        if (y)
          sdws [i][y] = sdws [i][y - 1] + arr [x][y];
        else
          sdws [i][y] = arr [x][y];
        x++; y++;
      }
    }

    long long ans = std::max ((long long)0, *std::max_element (sdws [0], sdws [0] + n));

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < (n - i); j++) {
        sdws [i][j] += *std::max_element (sdws [i - 1] + j, sdws [i - 1] + (n));
        ans = std::max (sdws [i][j], ans);
      }
    }

    printf ("%lld\n", ans);

  }
  return 0;
}
