#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

int main () {
  int n;
  scanf ("%d", &n);
  std::vector < std::pair <int, int> > vec;

  for (int i = 0; i < n; i++) {
    int x;   
    scanf ("%d", &x);
    vec.push_back (std::make_pair (x, i));
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    count += (n - 1 - vec[i].second) - (n - vec[i].first);
  }

  printf ("%d\n", count);

  return 0;
}
