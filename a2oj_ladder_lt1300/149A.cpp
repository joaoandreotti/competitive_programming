#include <bits/stdc++.h>

int main () {
  int k;
  scanf ("%d", &k);
  int arr [12];
  for (int i = 0; i < 12; i++)
    scanf ("%d", arr + i);
  std::sort (arr, arr + 12);
  int ans = 0;
  for (int i = 11; i >= 0; i--) {
    if (k <= 0)
      break;
    k -= arr [i];
    ans++;
  }
  if (k > 0)
    puts ("-1");
  else
    printf ("%d\n", ans);
  return 0;
}
