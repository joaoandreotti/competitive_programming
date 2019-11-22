#include <bits/stdc++.h>

const int MAXN = 60, MAXM = 1e6;

long long unsigned dp [MAXN][MAXM];

int32_t main () {
  int t, m, n;

  //printf ("%d\n", 1093897772L + 1431776536L);

  scanf ("%d%d%d", &t, &m, &n);

  dp [1][m] = 1;
  dp [1][n] = 1;

  for (int i = m + 1; i < n; i++)
    dp [1][i] = 2;


  for (int j = 1; j < t; j++) {
    for (int i = m; i <= n; i++) {
      if (i - 1 >= m)
        dp [j + 1][i - 1] += dp [j][i];
      if (i + 1 <= n)
        dp [j + 1][i + 1] += dp [j][i];
    }
  }

  /*
  for (int i = 1; i < t; i++) {
    for (int j = m; j <= 3; j++)
      printf ("%llu ", dp[i][j]);

    for (int j = n - 3; j <= n; j++)
      printf ("%llu ", dp[i][j]);
    puts ("");
  }
  */

  long long unsigned ans = 0;
  for (int i = m; i <= n; i++)
    ans += dp[t-1][i] % (long long)(1e9 + 7);

  printf ("%llu\n", ans % (long long)(1e9 + 7));

  return 0;
}
