#include <bits/stdc++.h>

int main () {
  int n, k;
  scanf ("%d%d", &n, &k);
  int arr [n];
  k--;

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  int lp = 0, flag = 0;
  for (int i = n - 1; i >= 0; i--) {
    lp = i;
    if (i - 1 >= 0 && arr [i] != arr [i - 1]) {
      flag = 1;
      break;
    }
  }

  if (lp > k)
    puts ("-1");
  else {
    if (flag)
      printf ("%d\n", lp);
    else
      puts ("0");
  }

  return 0;
}
