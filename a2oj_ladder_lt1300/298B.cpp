#include <bits/stdc++.h>

int main () {
  int t, x1, y1, x2, y2;
  scanf ("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
  int n = 0, s = 0, e = 0, w = 0;
  x2 - x1 >= 0 ? e = x2 - x1 : w = x1 - x2;
  y2 - y1 >= 0 ? n = y2 - y1 : s = y1 - y2;

  std::string str;
  std::cin >> str;
  long long ans = 0;
  //printf ("%d %d %d %d\n", n, s, e, w);
  for (int i = 0; i < str.size (); i++) {
    if (n && str [i] == 'N') {
      n--;
      ans = i + 1;
    }
    else if (s && str [i] == 'S') {
      s--;
      ans = i + 1;
    }
    else if (e && str [i] == 'E') {
      e--;
      ans = i + 1;
    }
    else if (w && str [i] == 'W') {
      w--;
      ans = i + 1;
    }
  }
  //printf ("%d %d %d %d\n", n, s, e, w);
  if (!n && !s && !e && !w)
    printf ("%lld\n", ans);
  else
    puts ("-1");
}
