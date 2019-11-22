#include <bits/stdc++.h>

const int MAXN = 5e1 + 1, MAXT = 2e2 + 1, INF = 0x3f3f3f3f;

int n, t, m1, m2;
int arr [MAXN], arr_1 [MAXN];
int fwd [MAXN], bwd [MAXN];
int fwd_st [MAXN][MAXT], bwd_st [MAXN][MAXT];
int dp [MAXN][MAXT];

/*
int func (int sttn, int tm) {
  int ans = INF;
  if (tm > t || sttn < 0 || sttn >= n)
    return INF;

  if (dp [sttn][tm])
    return dp [sttn][tm];

  if (sttn == (n - 1))
    ans = t - tm;

  printf ("sttn: %d, tm: %d\n", sttn, tm);
  if (sttn < (n - 1)) {
    int nxt = sttn == 0 ? arr [0] : arr [sttn] - arr [sttn - 1];
    for (int i = tm; i <= t; i++)
      if (fwd_st [sttn][i])
        ans = std::min (ans, func (sttn + 1, i + nxt));
  }

  if (sttn > 0) {
    int nxt = sttn == (n - 1) ? arr_1 [0] : arr_1 [sttn] - arr_1 [sttn + 1];
    for (int i = tm; i <= t; i++)
      if (bwd_st [sttn][i])
        ans = std::min (ans, func (sttn - 1, i + nxt));
  }

  return dp [sttn][tm] = ans;
}
*/

int f (int sttn, int tm) {
  if (tm > t or sttn > n)
    return INF;
  if (sttn == (n) and tm == t)
    return 0;

  if (~dp [sttn][tm])
    return dp [sttn][tm];

  dp [sttn][tm] = f (sttn, t + 1) + 1;
  if (fwd_st [sttn][tm])
    dp [sttn][tm] = std::min (dp [sttn][tm], f (sttn + 1, tm + arr [sttn]));
  if (bwd_st [sttn][tm])
    dp [sttn][tm] = std::min (dp [sttn][tm], f (sttn - 1, tm + arr [sttn - 1]));

  return dp [sttn][tm];
}

int main () {
  int tstcs = 1;
  while (scanf ("%d", &n) && n != 0) {
    scanf ("%d", &t);

    //memset (arr, 0, sizeof (arr));
    //memset (arr_1, 0, sizeof (arr_1));
    memset (dp, -1, sizeof (dp));
    memset (fwd_st, 0, sizeof (fwd_st));
    memset (bwd_st, 0, sizeof (bwd_st));

    for (int i = 1; i < n; i++)
      scanf ("%d", arr + i);

    scanf ("%d", &m1);
    int a;
    for (int i = 1; i <= m1; i++) {
      scanf ("%d", &a);
      for (int j = 1; j < n; j++) {
        fwd_st [j][a] = 1;
        a += arr [j];
      }
    }

    scanf ("%d", &m2);
    for (int i = 1; i <= m2; i++) {
      scanf ("%d", &a);
      for (int j = n; j > 1; j--) {
        bwd_st [j][a] = 1;
        a += arr [j - 1];
      }
    }

    /*
    for (int i = 0; i < m1; i++)
      fwd_st [0][fwd [i]] = 1;

    for (int i = 0; i < m1; i++)
      for (int j = 0; j < (n - 2); j++)
        fwd_st [j + 1][fwd [i] + arr [j]] = 1;

    for (int i = 0; i < m2; i++)
      bwd_st [n - 1][bwd [i]] = 1;

    for (int i = 0; i < m2; i++)
      for (int j = (n - 2); j > 0; j--)
        bwd_st [j][bwd [i] + arr_1 [j]] = 1;


    puts ("FULL MATRIX:");
    for (int j = 0; j <= t; j++)
      printf ("%2d ", j);
    puts ("");
    for (int i = 0; i < m1; i++) {
      for (int j = 0; j <= t; j++) {
        printf ("%2d ", fwd_st [i][j]);
      }
      puts ("");
    }
    */

    int ans = f (1, 0);

    if (ans < INF)
      printf ("Case Number %d: %d\n", tstcs++, ans);
    else
      printf ("Case Number %d: impossible\n", tstcs++);
  }
  return 0;
}
