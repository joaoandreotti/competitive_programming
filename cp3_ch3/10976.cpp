#include <bits/stdc++.h>

//double arr [(int)2e4 + 1];

std::vector <std::pair <int, int> > ans;

int main () {
  int n;
  while (scanf ("%d", &n) != EOF) {
    ans.clear ();

    for (int i = (n + 1); i <= (n * 2); i++) {
      if (abs (((n * i) % (n - i))) == 0)
        ans.push_back ({abs (((n * i) / (n - i))), i});
    }

    printf ("%d\n", ans.size ());
    for (int i = 0; i < ans.size (); i++) {
      printf ("1/%d = 1/%d + 1/%d\n", n, ans [i].first, ans [i].second);
    }

  }
  return 0;
}
