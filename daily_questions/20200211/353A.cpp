#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e2 + 1;

int n;
std::pair <int, int> arr [MAXN];

void input () {
  scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d%d", &arr [i].first, &arr [i].second);

  solve ();
}

void solve () {
  int upper = arr [0].first, lower = arr [0].second;

  int ans = 0;

  for (int i = 1; i < n; i++) {
    printf ("upper: %d, lower: %d\n", upper, lower);

    if (upper % 2)
      if (arr [i].second % 2 && arr [i].first % 2 == 0) {
        ans++;
        upper += arr [i].second;
        lower += arr [i].first;
      }
      else {
        upper += arr [i].first;
        lower += arr [i].second;
      }
    else if (lower % 2)
      if (arr [i].first % 2 && arr [i].second % 2 == 0) {
        ans++;
        upper += arr [i].second;
        lower += arr [i].first;
      }
      else {
        upper += arr [i].first;
        lower += arr [i].second;
      }
    else {
      upper += arr [i].first;
      lower += arr [i].second;
    }
  }

  printf ("upper: %d, lower: %d\n", upper, lower);
  if (upper % 2 == 0 && lower % 2 == 0)
    printf ("%d\n", ans);
  else
    puts ("-1");
}

int main () {
  input ();
  return 0;
}
