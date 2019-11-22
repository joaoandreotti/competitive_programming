#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 3e3 + 1;

long long n, t;
std::pair <long long, long long> arr [MAXN];
long long dp [MAXN][MAXN];

long long f (long long x, long long r) {
  if (x >= n || r < 1)
    return dp [x][r] = 0;
  if (dp [x][r] != -1)
    return dp [x][r];


  return dp [x][r] = std::max (f (x + 1, r), f (x + 1, r - arr [x].first) + arr [x].second);
}

void input () {
  scanf ("%lld%lld", &n, &t);
  for (long long i = 0, a, b; i < n; i++) {
    scanf ("%lld%lld", &a, &b);
    arr [i] = std::make_pair (a, b);
  }

  memset (dp, -1, sizeof dp);

  solve ();
}

void solve () {
  std::sort (arr, arr + n);
  printf ("%lld\n", f (0, t));
}

int main () {
  input ();
  return 0;
}
