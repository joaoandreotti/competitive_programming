#include <bits/stdc++.h>
using namespace std;
#define T 202
#define oo 0x3f3f3f3f

int tc, n, t, m, s, c[T];
int fwd[T][T];
int bwd[T][T];
int memo[T][T];

int f(int st, int tm) {
  if (tm > t or st > n) return oo;
  if (st == n and tm == t) return 0;

  int& ans = memo[st][tm];
  if (~ans) return ans;

  ans = f(st, tm+1)+1;
  if (fwd[st][tm]) ans = min (ans, f(st+1, tm+c[st]));
  if (bwd[st][tm]) ans = min (ans, f(st-1, tm+c[st-1]));

  return ans;
}

int main () {
  while (scanf ("%d", &n) and n) {
    memset(memo, -1, sizeof memo);
    memset(fwd, 0, sizeof fwd);
    memset(bwd, 0, sizeof bwd);

    scanf ("%d", &t);
    for (int i = 1; i < n; i++) {
      scanf ("%d", &c [i]);
    }
    
    scanf ("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf ("%d", &s);
      for (int j = 1; j < n; j++) {
        fwd[j][s] = 1;
        s += c[j];
      }
    }

    scanf ("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf ("%d", &s);
      for (int j = n; j > 1; j--) {
        bwd[j][s] = 1;
        s += c[j-1];
      }
    }

    printf ("Case Numer %d: ", ++tc);
    int ans = f(1, 0);
    if (ans < oo) printf ("%d\n", ans);
    else printf ("impossible\n");
  }
  return 0;
}
