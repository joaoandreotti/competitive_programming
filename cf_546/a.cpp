#include <bits/stdc++.h>

const int MAXN = 1e2 + 1;

typedef std::pair <int, int> pi;

int n, k;
pi arr [MAXN];

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d%d", &arr [i].first, &arr [i].second);
  std::sort (arr, arr + n);
  scanf ("%d", &k);

  int count = 0;
  for (int i = 0; i < n; i++)
    if (k > arr [i].second)
      count++;

  printf ("%d\n", n - count);

  return 0;
}
