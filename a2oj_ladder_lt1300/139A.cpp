#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  int arr [7];
  for (int i = 0; i < 7; i++)
    scanf ("%d", arr + i);

  int day = 0;
  while (n > 0) {
    n -= arr [day++ % 7];
  }
  printf ("%d\n", day % 7 == 0 ? 7 : day % 7);
  return 0;
}
