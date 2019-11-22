#include <bits/stdc++.h>

int arr [(int)1e3 + 1];
int d [(int)1e3 + 1];

int main () {
  int n; scanf ("%d", &n);

  for (int i = 1; i <= n; i++)
    scanf ("%d", arr + i);

  for (int i = 2; i < n; i++) {
    if (arr [i - 1] == 1 && arr [i] == 0 && arr [i + 1] == 1) {
      //printf ("%d ", i);
      d [i] = 1;
    }
  }

  int ans = 0;
  if (n == 3) {
    if (d[2] == 1)
      ans = 1;

    printf ("%d\n", ans);
    return 0;
  }


  for (int i = 2; i <= (n - 2); i++) {
    if (d [i] == 1) {
      d [i + 2] = 0;
      ans++;
    }
  }

  if (d [n - 1] == 1) {
    ans++;
  }

  printf ("%d\n", ans);


  return 0;
}
