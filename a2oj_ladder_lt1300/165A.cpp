#include <bits/stdc++.h>

std::pair <int, int> sorted_x[200], sorted_y[200];
std::map <std::pair <int, int>, int> bitmap;

bool comp_y (std::pair <int, int> a, std::pair <int, int> b) {
  if (b.second == a.second)
    return b.first > a.first;
  return b.second > a.second;
}

int main () {
  int n;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf ("%d%d", &a, &b);
    sorted_x [i] = {a, b};
    sorted_y [i] = {a, b};
    bitmap [{a, b}] = 0;
  }
  std::sort (sorted_x, sorted_x + n);
  std::sort (sorted_y, sorted_y + n, comp_y);

  for (auto i = 1; i < n - 1; i++) {
    // left
    if (sorted_y [i].second == sorted_y [i - 1].second && sorted_y [i].first > sorted_y [i - 1].first)
      bitmap [{sorted_y [i].first, sorted_y [i].second}]++;
    // right
    if (sorted_y [i].second == sorted_y [i + 1].second && sorted_y [i].first < sorted_y [i + 1].first)
      bitmap [{sorted_y [i].first, sorted_y [i].second}]++;
  }
  for (auto i = 1; i < n - 1; i++) {
    // down
    if (sorted_x [i].first == sorted_x [i - 1].first && sorted_x [i].second > sorted_x [i - 1].second)
      bitmap [{sorted_x [i].first, sorted_x [i].second}]++;
    // up
    if (sorted_x [i].first == sorted_x [i + 1].first && sorted_x [i].second < sorted_x [i + 1].second)
      bitmap [{sorted_x [i].first, sorted_x [i].second}]++;
  }

  long long ans = 0;
  for (auto i = bitmap.begin (); i != bitmap.end (); i++)
    if (i->second == 4)
      ans++;

  printf ("%lld\n", ans);

  return 0;
}
