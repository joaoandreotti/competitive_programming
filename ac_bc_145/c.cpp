#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 10;

int n;
std::pair <int, std::pair <int, int> > towns [MAXN];

void input () {
  scanf ("%d", &n);
  for (int i = 0, a, b; i < n; i++) {
    scanf ("%d %d", &a, &b);
    towns [i] = std::make_pair (i, std::make_pair (a, b));
  }

  solve ();
}

void solve () {
  double ans = 0;
  long long count = 0;
  do {
    for (int i = 0; i < n - 1; i++)
      ans += std::hypot (towns [i].second.first - towns [i + 1].second.first, towns [i].second.second - towns [i + 1].second.second);

  } while (std::next_permutation (towns, towns + n));

  double fat = 1;
  for (int i = n; i > 0 ; i--)
    fat *= i;

  ans = ans / fat;

  printf ("%.10lf\n", ans);
}

int main () {
  input ();
  return 0;
}
