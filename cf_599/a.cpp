#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e3 + 1;

int t, n;
int arr [MAXN];

void input () {
  scanf ("%d", &t);
  for (int cs = 0; cs < t; cs++) {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
      scanf ("%d", arr + i);

    solve ();
  }
}

void solve () {
  std::sort (arr, arr + n, std::greater <int> ());

  int crr = 1;
  for (int i = 1; i < n; i++)
    crr = std::max (std::min (i + 1, arr [i]), crr);

  printf ("%d\n", crr);
}

int main () {
  input ();
  return 0;
}
