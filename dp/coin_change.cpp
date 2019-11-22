#include <bits/stdc++.h>
int n, k;
int coins[(int)1e3];
int dp[(int)1e3 + 1][(int)1e5];

int cc_nodp (int cp, int rem) {
  if (dp[cp][rem] != -1)
    return dp[cp][rem];

  if (rem == 0)
    return 0;
  if (rem < 0 || cp >= n)
    return 0x3f3f3f3f;

  return dp[cp][rem]=std::min (cc_nodp (cp + 1, rem - coins[cp]) + 1, cc_nodp (cp + 1, rem));
}

int main () {
  memset(dp, -1, sizeof (dp));
  scanf ("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf ("%d", coins + i);

  printf ("%d\n", cc_nodp (0, k));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++)
      printf ("%d ", dp[i][j]);
    puts("");
  }
    


  return 0;
}
