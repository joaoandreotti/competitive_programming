#include <bits/stdc++.h>

const int MAXN = 1e3 + 1;

int arr [26];
std::bitset <26> bs [MAXN];

int main () {
  int T; scanf ("%d", &T);

  while (T--) {
    int n; scanf ("%d", &n);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < 26; j++)
        bs [i][j] = 0;

    for (int i = 0; i < n; i++) {
      std::string str;
      std::cin >> str;
      for (int j = 0; j < str.size (); j++) {
        bs [i][str [j] - 'a'] = 1;
      }
    }

    std::bitset <26> res = bs [0];
    for (int i = 1; i < n; i++) {
      res = res & bs [i];
    }

    //std::cout << res << '\n';

    long long x = 0;
    for (int i = 0; i <= 25; i++) {
      if (res [i] & 1)
        x++;
    }

    printf ("%lld\n", x);
  }

  return 0;
}
