#include <bits/stdc++.h>

const int MAXN = 1e4;

const double EPS = 1e-5;
const double pi = acos (-1);
double arr [MAXN];
int n, f;

bool check (double area) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += floor (arr [i] / area);

  return sum >= f;
}

int main () {
  int T; scanf ("%d", &T);

  while (T--) {
    scanf ("%d%d", &n, &f);
    f++;

    double max = 0;
    for (int i = 0; i < n; i++) {
      scanf ("%lf", arr + i);
      arr [i] = (arr [i] * arr [i]) * pi;
      max = std::max (max, arr [i]);
    }

    // binary search the answer
    double h = max, l = 0, mid = (h + l) / 2.0;

    double ans = 0;
    while (h >= l) {
      if (check (mid)){
        l = mid + EPS;
        ans = mid;
      }
      else h = mid - EPS;
      mid = (h + l) / 2.0;
    }

    printf ("%lf\n", ans);

  }
  return 0;
}
