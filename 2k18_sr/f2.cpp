#include <bits/stdc++.h>

typedef std::vector <std::pair <std::pair<int, int>, std::pair<int, int> > > vppi;
vppi stg;
int dp [(int)1e3][(int)pow (2, 10)];
int next [(int)1e3];
int n;

int func (int crr, int bm) {
  //printf ("crr: %d, bm: %d, ", crr, bm);
  //printf ("songs[crr]: %d, next [crr]: %d, pd: %d\n", stg[crr].second.second, next[crr], dp [crr][bm]);
  if (crr >= stg.size ()) {
    if (bm == (int)pow (2, n) - 1)
      return 0;

    return -1;
  }

  if (dp [crr][bm] != -2)
    return dp[crr][bm];

  int a = func (next [crr], bm | (1 << stg[crr].second.first));
  int b = func (crr + 1, bm);

  if (a >= 0)
    a += stg[crr].second.second;
   
  //printf ("pegando: %d, nao pegando: %d\n", a, b);

  return dp [crr][bm] = std::max (a, b);
}

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    for (int j = 0; j < a; j++) {
      int s, e, p;
      scanf ("%d%d%d", &s, &e, &p);
      stg.push_back ({{s, e}, {i, p}});
    }
  }
  for (int i = 0; i < stg.size (); i++)
    for (int j = 0; j < (int)pow (2, n); j++)
      dp[i][j] = -2;

  std::sort (stg.begin (), stg.end ());

/*
  for (int i = 0; i < stg.size (); i++)
    printf ("{{%d, %d}, {%d, %d}}\n", stg[i].first.first, stg[i].first.second, stg[i].second.first, stg[i].second.second);
    */

  for (int i = 0; i < stg.size (); i++) {
    for (int j = i + 1; j < stg.size (); j++)
      if (stg[j].first.first >= stg[i].first.second) {
        next[i] = j;
        break;
      }
  }

  //printf ("{");
  for (int i = 0; i < stg.size (); i++) {
    if (!next[i])
      next[i] = stg.size ();
    //printf ("%d, ", next[i]);
  }
  //printf ("\b\b}\n");

  int ans = func (0, 0);

  /*
  printf ("DP: \n");
  for (int i = 0; i < stg.size (); i++) {
    for (int j = 0; j < (int)pow (2, n); j++)
      printf ("%d ", dp [i][j]);
    puts ("");
  }
  */


  printf ("%d\n", ans);
  return 0;
}
