#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

int t, n, min = (int)1e9;

int arr [MAXN];
int occ [MAXN];

void input () {
  scanf ("%d", &t);

  for (int cs = 0; cs < t; cs++) {
    scanf ("%d", &n);
    min = (int)1e9;
    memset (arr, 0, sizeof arr);
    memset (occ, 0, sizeof occ);
    for (int i = 0, a; i < n; i++) {
      scanf ("%d", &a);
      occ [a]++;
      if (occ [a] == 1);
      else
        min = std::min (min, i - arr [a]);

      arr [a] = i;
    }

    solve ();
  }
}

void solve () {
  /*
  std::sort (arr, arr + n);

  int min = (int)1e9;

  int j = 0;
  for (int i = 0; i < n; i++) {
    j = i + 1;
    if (i + 1 < n && arr [i].first == arr [j].first)
      min = std::min (min, arr [j].second - arr [i].second);
  }
    */

  if (min == (int)1e9 || (min + 1) < 2)
    puts ("-1");
  else
    printf ("%d\n", min + 1);
}

int main () {
  input ();
  return 0;
}
