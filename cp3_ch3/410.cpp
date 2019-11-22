#include <bits/stdc++.h>

const int MAXN = 10;

int n, s;
int arr [MAXN], cm [MAXN];
std::vector <int> usd [MAXN];
float am;

int main () {
  int T = 0;

  while (scanf ("%d%d", &n, &s) != EOF) {
    if (T)
      puts ("");
    am = 0;
    memset (arr, 0, sizeof (arr));
    for (int i = 0; i < s; i++) {
      scanf ("%d", arr + i);
      am += arr [i];
    }

    for (int i = 0; i < 10; i++)
      usd [i].clear ();


    am /= n;

    std::sort (arr, arr + (2 * n));

    /*
    int cnt = s - 1;
    for (int i = 0; i < n; i++) {
      if (cnt >= 0) {
        cm [i] = arr [cnt--];
        usd [i].push_back (cm [i]);
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if (cnt >= 0) {
        cm [i] += arr [cnt--];
        usd [i].push_back (arr [cnt + 1]);
      }
    }
    */

    int max = (2 * n) - 1;
    for (int i = 0; i < (2 * n); i++) {
      usd [i].push_back (arr [i]);
      usd [i].push_back (arr [max - i]);
    }

    float ans = 0;
    printf ("Set #%d\n", ++T);
    for (int i = 0; i < n; i++) {
      float tmp = 0;
      printf (" %d:", i);
      for (int j = 0; j < usd [i].size (); j++) {
        if (usd [i][j])
          printf (" %d", usd [i][j]);
        tmp += usd [i][j];
      }
      puts ("");
      ans += fabs (tmp - am);
    }
    printf ("IMBALANCE = %.5f\n", ans);

  }

  return 0;
}
