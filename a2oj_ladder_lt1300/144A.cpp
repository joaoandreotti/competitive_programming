#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  int max = 0, min = 0x3f3f3f3f;
  int maxp, minp;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      maxp = i;
    }
    if (arr[i] <= min) {
      min = arr[i];
      minp = i + 1;
    }
  }
  
  //printf ("maxp: %d, minp: %d\n", maxp, minp);

  if (minp <= maxp)
    printf ("%d\n", maxp + (n - minp) - 1);
  else
    printf ("%d\n", maxp + (n - minp));
  return 0;
}
