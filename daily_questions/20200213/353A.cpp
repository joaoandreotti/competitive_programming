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
  int upper = 0, lower = 0;

  for (int i = 0; i < n; i++) {
    upper += arr [i].first;
    lower += arr [i].second;
  }

  int flag = 0;
  int ans = 0;
  if (upper % 2 && lower % 2) {
    // .first even, .second odd
    // or vice-versa
    for (int i = 0; i < n; i++)
      if (arr [i].first % 2 == 0 && arr [i].second % 2) {
        flag = 1;
        ans = 1;
        break;
      }
      else if (arr [i].first % 2 && arr [i].second % 2 == 0) {
        flag = 1;
        ans = 1;
        break;
      }
  }
  else if (upper % 2 && !(lower % 2)) {
    // impossible
    flag = 0;
  }
  else if (!(upper % 2) && lower % 2) {
    // impossible
    flag = 0;
  }
  else {
    flag = 1;
  }

  if (flag)
    printf ("%d\n", ans);
  else
    puts ("-1");
}

int main () {
  input ();
  return 0;
}
