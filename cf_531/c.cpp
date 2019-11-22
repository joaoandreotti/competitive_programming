#include <bits/stdc++.h>

int arr [(int)1e3 + 1];

int main () {
  int n, x, y; scanf ("%d%d%d", &n, &x, &y);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  if (x <= y) {
    int count = 0;
    for (int i = 0; i < n; i++)
      if (arr [i] <= x)
        count++;

    if (count % 2)
      printf ("%d\n", (count / 2) + 1);
    else
      printf ("%d\n", (count / 2));
  }
  else
    printf ("%d\n", n);
  return 0;
}
