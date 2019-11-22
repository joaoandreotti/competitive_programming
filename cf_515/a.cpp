#include <bits/stdc++.h>

int main () {
  int t; scanf ("%d", &t);

  for (int c = 0; c < t; c++) {
    int l, v, start, end;
    scanf ("%d%d%d%d", &l, &v, &start, &end);

    if (start % v)
      start += v - (start % v);

    if (end % v)
      end -= (end % v);


    int a;
    a = (end - start) / v;
    a++;

    //printf ("start: %d, end: %d, a: %d\n", start, end, a);

    printf ("%d\n", (l / v) - (a));
  }
  return 0;
}
