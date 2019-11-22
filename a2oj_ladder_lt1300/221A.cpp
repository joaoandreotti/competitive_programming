#include <bits/stdc++.h>

int arr [(int)1e3 + 1];

int main () {
  int n;
  scanf ("%d", &n);
  arr [0] = n;
  for (int i = 1; i < n; i++)
    arr [i] = i;

  for (int i = 0; i < n; i++)
    printf ("%d ", arr [i]);
  puts ("");

  return 0;
}
