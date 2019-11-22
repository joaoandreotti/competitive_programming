#include <bits/stdc++.h>

int main () {
  int tc; scanf ("%d", &tc);
  int arr [3];
  int n = tc;

  while (tc--) {
    scanf ("%d%d%d", &arr[0], &arr[1], &arr[2]);
    std::sort (arr, arr + 3);

    printf ("Case %d: %d\n", n - tc, arr [1]);

  }
  
  return 0;
}
