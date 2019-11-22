#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

int n, m;
std::vector <std::pair <int, int> > arr;

int dp [MAXN];

int f (int x) { // dp [x] => cost to fill [x + 1, m];
  if (x <= 0)
    return 0;

  if (dp [x] != -1)
    return dp [x];

  dp [x] = INT_MAX;
  for (int i = 0; i < n; i++) {
    int l = arr [i].first - arr [i].second;
    int r = arr [i].first + arr [i].second;

    if (x < l) {
      int d = l - x;

      arr [i].second += d;
      dp [x] = std::min (dp [x], f (x - 1) + d);
      arr [i].second -= d;
    }
    else if (x > r) {
      int d = x - r;

      arr [i].second += d;
      dp [x] = std::min (dp [x], f (l - d - 1) + d);
      arr [i].second -= d;
    }
    else
      dp [x] = std::min (dp [x], f (l - 1));
  }

  return dp [x];
}

void input () {
  scanf ("%d%d", &n, &m);
  for (int i = 0, a, b; i < n; i++) {
    scanf ("%d%d", &a, &b);
    arr.push_back ({a, b});
  }
  solve ();
}

void solve () {
  memset (dp, -1, sizeof dp);
  printf ("%d\n", f (m));
}

int main () {
  input ();
  return 0;
}
