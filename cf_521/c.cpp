#include <bits/stdc++.h>

std::vector <int> ans;
std::vector <std::pair <int, int> > arr;
std::vector <std::pair <std::pair <int, int>, int> > sums;

bool cmp (std::pair <int, int> a, int b) {
  return a.first < b;
}

int main () {
  int n; scanf ("%d", &n);
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    arr.push_back ({a, i + 1});
    sum += arr [i].first;
  }

  std::sort (arr.begin (), arr.end ());

  int max = arr [n - 1].first;
  int pos = arr [n - 1].second;
  for (int i = 0; i < n; i++) {
    if (i != n - 1) {
      sums.push_back ({{sum - arr [i].first, max}, arr [i].second});
    }
    else {
      auto x = std::lower_bound (arr.begin (), arr.end (), max, cmp);
      if (x != arr.begin ())
        x--;
      sums.push_back ({{sum - arr [i].first, x->first}, arr [i].second});
    }
  }
    
  for (int i = 0; i < sums.size (); i++) {
    printf ("{{%d, %d}, %d} ", sums [i].first.first, sums [i].first.second, sums[i].second);
  }
  puts ("");


  for (int i = 0; i < sums.size (); i++)
    if (sums [i].first.first - sums [i].first.second == sums [i].first.second)
      ans.push_back (sums[i].second);

  printf ("%d\n", (int)ans.size ());
  for (int i = 0; i < ans.size (); i++)
    printf ("%d ", ans [i]);

  puts ("");
  return 0;
}
