#include <bits/stdc++.h>

const int MAXN = 1e5 + 1, MAXQ = 1e6 + 1;

typedef std::pair <int, int> pi;
typedef std::pair <pi, std::string> pis;

pis arr [MAXN];

bool cmp (pis a, int b) {
  return b >= a.first.first;
}

int main () {
  int T; std::cin >> T;


  while (T--) {
    int n; std::cin >> n;
    for (int i = 0; i < n; i++)
      std::cin >> arr [i].second >> arr [i].first.first >> arr [i].first.second;

    std::sort (arr, arr + n);

    int q; std::cin >> q;
    while (q--) {
      int p; std::cin >> p;
      int count = 0;

      std::string ans;

      for (int i = 0; i < n; i++) {
        if (p >= arr [i].first.first && p <= arr [i].first.second) {
          count++;
          ans = arr [i].second;
        }


        if (count >= 2) {
          break;
        }
      }

      if (count == 1)
        printf ("%s\n", ans.c_str ());
      else
        puts ("UNDETERMINED");

    }

    if (T)
      puts ("");

  }
  return 0;
}
