#include <bits/stdc++.h>

const int MAXN = 1e5 + 1;
const double EPS = 1e9;

int n;
int arr [MAXN];

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  int cnt = 0, m = *std::max_element (arr, arr + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr [i] == m)
      cnt++;
    else
      cnt = 0;
    ans = std::max (ans, cnt);
  }

  printf ("%d\n", ans);
  return 0;
}
