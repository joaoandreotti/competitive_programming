#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e3 + 1;

int n;
std::pair <int, int> arr [MAXN];

void input () {
  scanf ("%d", &n);

  for (int i = 0; (i < n) && scanf ("%d", &arr [i].first); i++) 
    arr [i].second = i + 1;

  solve ();
}

void solve () {
  std::sort (arr, arr + n, std::greater <std::pair <int, int> > ());

  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += arr [i].first * (i) + 1;

  printf ("%lld\n", ans);
  for (int i = 0; i < n; i++)
    if (i + 1 < n)
      printf ("%d ", arr [i].second);
    else
      printf ("%d\n", arr [i].second);
}

int main () {
  input ();
  return 0;
}
