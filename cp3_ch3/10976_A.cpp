#include <bits/stdc++.h>

const double EPS = 1e-9;

std::vector <std::pair <int, int> > ans;

int main () {
  double n;
  while (scanf ("%lf", &n) != EOF) {
    double y;

    ans.clear ();
    for (double i = n + 1; i <= (2 * n); i++) {
      y = fabs ((n * i) / (n - i));

      if (fabs (((1/y) + (1/i)) - (1/n)) < EPS)
        ans.push_back ({(int)y, (int)i});
    }

    if (ans.size () >= n) {
      puts ("to big");
      continue;
    }

    printf ("%d\n", ans.size ());
    for (int i = 0; i < ans.size (); i++)
      printf ("1/%.0lf = 1/%d + 1/%d\n", n, ans [i].first, ans [i].second);
  }
  return 0;
}
