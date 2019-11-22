#include <bits/stdc++.h>

std::pair <std::pair <int, int>, int> arr [(int) 1e5 + 1];

bool cmp (std::pair <std::pair <int, int>, int> a, std::pair <std::pair <int, int>, int> b) {
  return b.second > a.second;
}

int main () {
  int t; scanf ("%d", &t);
  while (t--) {
    int n; scanf ("%d", &n);

    for (int i = 0; i < n; i++) {
      int a, b; scanf ("%d%d", &a, &b);
      arr [i].first.first = a;
      arr [i].first.second = b;
      arr [i].second = i;
    }
    std::sort (arr, arr + n);
    std::pair <int, int> itr;

    itr.first = arr[0].first.first;
    itr.second = arr[0].first.second;
    int count = 1;
    for (int i = 1; i < n; i++) {
      if (itr.second >= arr [i].first.first) {
        count++;
        itr.second = std::max (itr.second, arr [i].first.second);
      }
    }

    if (count == n)
      puts ("-1");
    else {
      std::sort (arr, arr +n, cmp);
      for (int i = 0; i < n; i++) {
        if (itr.second >= arr [i].first.first) {
          printf ("1 ");
        }
        else
          printf ("2 ");
      }
      puts ("");
    }
  }
  return 0;
}
