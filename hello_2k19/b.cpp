#include <bits/stdc++.h>

int arr [15];
int n, flag;

void f (int pos, int res) {
  if (pos > n)
    return;
  if (pos == n) {
    if (res % 360 == 0)
      flag = 1;
  }

  f (pos + 1, res + arr [pos]);
  f (pos + 1, res - arr [pos]);
}

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  f (0, 0);

  if (flag)
    puts ("YES");
  else
    puts ("NO");
  return 0;
}
