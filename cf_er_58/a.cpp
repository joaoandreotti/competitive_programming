#include <bits/stdc++.h>

int arr [(int)1e5];

int main () {
  int n; scanf ("%d", &n);
  for (int t = 0; t < n; t++) {
    int l, r, d;
    scanf ("%d%d%d", &l, &r, &d);

    if (d < l) {
      printf ("%d\n", d);
    }
    else {
      if (((r + 1) % d) == 0)
        printf ("%d\n", (r + 1) + (((r + 1) % d)));
      else
        printf ("%d\n", (r + 1) + (d - ((r + 1) % d)));
    }
  }
  return 0;
}
