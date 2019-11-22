#include <bits/stdc++.h>
int arr [(int)1e5];

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  scanf ("%d", arr);
  for (int i = 1; i < m; i++) {
    scanf ("%d", arr + i);
    if (arr[i] == arr[i - 1])
      arr [i] = 0;
  }

  /*
  puts ("arr: ");
  for (int i = 0; i < m; i++)
    printf ("%d ", arr [i]);
  puts ("");
  */

  long long ans = arr [0] - 1;
  int last = arr [0];
  //printf ("ans: %lld\n", ans);
  for (int i = 1; i < m; i++) {
    if (arr [i]) {
      if (arr [i] < last)
        ans += arr[i] + (n - last);
      else
        ans += arr[i] - last;
      last = arr [i];
    }
    else {
      for (int j = i; i >= 0; j--)
        if (arr [j]) {
          last = arr [j];
          break;
        }
    }
    //printf ("ans: %lld\n", ans);
  }
  printf ("%lld\n", ans);
  return 0;
}
