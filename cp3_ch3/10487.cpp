#include <bits/stdc++.h>

const int MAXN = 1e3 + 1;

int arr [MAXN];

int main () {
  int n, tcase = 1;
  while (scanf ("%d", &n) && n != 0) {
    printf ("Case %d:\n", tcase++);

    for (int i = 0; i < n; i++)
      scanf ("%d", arr + i);

    std::sort (arr, arr + n);

    int q; scanf ("%d", &q);
    for (int i = 0; i < q; i++) {
      int p; scanf ("%d", &p);

      int min = INT_MAX;
      int ans = 0;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (j != k) {
            //printf ("j: %d, k: %d, ", arr [j], arr [k]);
            //printf ("sum: %d\n", abs ((arr [j] + arr [k]) - p));
            if (abs((arr [j] + arr [k]) - p) < min) {
              min = abs ((arr [j] + arr [k]) - p);
              ans = (arr [j] + arr [k]);
            }
          }
        }
      }

      printf ("Closest sum to %d is %d.\n", p, ans);
    }
  }
  return 0;
}
