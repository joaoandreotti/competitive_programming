#include <bits/stdc++.h>

const int MAXN = 1e6 + 10;

int dp [MAXN];
int k, l, r;

int func (int c) {
  if (c <= 0 || dp[c] >= 0)
    return -1;

  func (c-1); func (c-k); func (c-l);

  //printf ("c: %d, dp[c]: %d, dp[c-1]: %d, dp [c-k]: %d, dp[c-l]: %d\n", c, dp [c], dp [c-1], dp [c-k], dp [c-l]);
  if (dp [c-1] == 0 || ((c-k) > 0 && dp [c-k] == 0) || ((c-l) > 0 && dp [c-l] == 0))
    return dp [c] = 1;
  else if (dp [c] == -1)
    return dp [c] = 0;

  return dp [c];
}

int main () {
  int m; scanf ("%d%d%d", &k, &l, &m);


  memset (dp, -1, sizeof (dp));
  dp [1] = dp [k] = dp [l] = 1;
  func (MAXN - 1);

  /*
  for (int i = 1; i <= 113; i++) {
    printf ("dp [%d]: %d\n", i, dp [i]);
  }
  */
  for (int t = 0; t < m; t++) {
    scanf ("%d", &r);
    //printf ("r: %d\n", r);
    if (dp [r] == 1)
      printf ("A");
    else
      printf ("B");
  }
  puts ("");
  return 0;
}
