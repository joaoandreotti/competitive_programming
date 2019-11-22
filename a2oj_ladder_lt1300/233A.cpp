#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  if (n % 2 == 1) {
    puts ("-1");
    return 0;
  }
  int arr [n];
  for (int i = 0; i < n; i++)
    arr [i] = i + 1;

  for (int i = 0; i < n - 1; i += 2)
    std::swap (arr[i], arr[i + 1]);

  for (int i = 0; i < n; i++)
    if (i + 1 < n)
      printf ("%d ", arr[i]);
    else
      printf ("%d", arr[i]);
  puts ("");
  return 0;
}
