#include <bits/stdc++.h>

const int MAXT = 2e2 + 2, INF = 0x3f3f3f3f;

int n, m, t, a, cs = 1, arr [MAXT];
int fwd [MAXT][MAXT];
int bwd [MAXT][MAXT];
int dp [MAXT][MAXT];

int f (int st, int tm) {
  if (tm > t or st > n) return INF;
  if (st == n and tm == t) return 0;

  int &ans = dp [st][tm];
  if (~(ans)) return ans;

  ans = f (st, tm + 1) + 1;
  if (fwd [st][tm]) ans = std::min (ans, f (st + 1, tm + arr [st]));
  if (bwd [st][tm]) ans = std::min (ans, f (st - 1, tm + arr [st - 1]));

  return ans;
}

int main () {
  while (scanf ("%d", &n) && n) {
    memset (dp, -1, sizeof dp);
    memset (fwd, 0, sizeof fwd);
    memset (bwd, 0, sizeof bwd);

    scanf ("%d", &t);
    for (int i = 1; i < n; i++) {
      scanf ("%d", arr + i);
    }

    scanf ("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf ("%d", &a);
      for (int j = 1; j < n; j++) {
        fwd [j][a] = 1;
        a += arr [j];
      }
    }
    
    scanf ("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf ("%d", &a);
      for (int j = n; j > 1; j--) {
        bwd [j][a] = 1;
        a += arr [j - 1];
      }
    }

    int ans = f (1, 0);
    if (ans < INF) printf ("Case Number %d: %d\n", cs++, ans);
    else printf ("Case Number %d: impossible\n", cs++);

  }
  return 0;
}
