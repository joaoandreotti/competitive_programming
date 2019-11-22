#include <bits/stdc++.h>

const int MAXN = 2e5 + 1;

long double arr [MAXN];

int main () {
  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%Lf", arr + i);

  std::sort (arr, arr + n);

  puts ("arr:");
  for (int i = 0; i < n; i++)
    printf ("%Lf  ", arr[i]);
  puts ("");

  long double x;
  long double ans = 0;
  for (int i = 0; i < n; i++)
    x += arr [i];
  x /= (long double)n;


  printf ("x: %Lf\n", x);
  printf ("ans: %Lf", ans);
  for (int i = 0; i < n; i++) {
    ans += arr [i] / x;
    printf (" %Lf", ans);
  }
  puts ("\n--");


  printf ("%Lf\n", std::abs (ans));

  return 0;
}
