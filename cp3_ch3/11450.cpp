#include <bits/stdc++.h>

const int MAXM= 201, MAXC = 21;

int m, c, dp [MAXM][MAXC], bm [MAXC];
std::vector <int> arr [MAXC];

int f (int m, int p) {
  if (dp [m][p] != -1)
    return dp [m][p];
  if (c == p)
    return dp [m][p] = 0;

  for (int i = 0; i < arr [p].size (); i++) {
    if (m - arr [p][i] >= 0)
      dp [m][p] = std::max (f (m - arr [p][i], p + 1) + arr [p][i], dp [m][p]);
  }

  //printf ("p: %d, best: %d\n", p, dp [m][p]);

  return dp [m][p];
}

int main () {
  int T; scanf ("%d", &T);

  while (T--) {
    scanf ("%d%d", &m, &c);
    for (int i = 0; i < c; i++)
      arr [i].clear ();
    memset (dp, -1, sizeof (dp));
    memset (bm, 0, sizeof (bm));

    int a;
    for (int i = 0; i < c; i++) {
      int k; scanf ("%d", &k);
      for (int j = 0; j < k; j++) {
        scanf ("%d", &a);
        arr [i].push_back (a);
      }
    }

    f (m, 0);

    for (int i = 0; i <= m; i++)
      for (int j = 0; j < c; j++)
        if (dp [i][j] != -1)
          bm [j] = 1;

    int flag = 1;
    for (int i = 0; i < c; i++)
      if (!bm [i])
        flag = 0;

    if (flag)
      printf ("%d\n", f (m, 0));
    else
      puts ("no solution");

  }
  return 0;
}
