#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf ("%d", arr + i);
    if  (arr[i] % 2 == 0)
      arr[i]--;
  }
  for (int i = 0; i < n; i++)
    if (i + 1 < n)
      printf ("%d ", arr [i]);
    else
      printf ("%d\n", arr [i]);
  //puts ("");
  return 0;
}
