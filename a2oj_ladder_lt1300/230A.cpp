#include <bits/stdc++.h>

int comp (std::pair <int, int> a, std::pair <int, int> b) {
  if (a.first == b.first)
    return b.second < a.second;
  return b.first > a.first;
}

int main () {
  int s, n;
  scanf ("%d%d", &s, &n);
  int a, b;
  std::pair <int, int> arr[n];
  for (int i = 0; i < n; i++) {
    scanf ("%d%d", &a, &b);
    arr [i] = {a, b};
  }

  std::sort (arr, arr + n, comp);

  for (int i = 0; i < n; i++) {
    if (s > arr [i].first)
      s += arr [i].second;
    else {
      puts ("NO");
      return 0;
    }
  }

  puts ("YES");
  
  return 0;
}
