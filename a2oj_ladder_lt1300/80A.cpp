#include <bits/stdc++.h>

bool prime (int a) {
  if (a == 1)
    return 0;
  for (int i = 2; (i * i) <= a; i++) {
    if (a % i == 0)
      return 0;
  }
  return 1;
}

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  for (int i = n + 1; i <= m; i++) {
    if (prime (i)) {
      if (i == m) {
        puts ("YES");
        return 0;
      }
      else {
        puts ("NO");
        return 0;
      }
    }
  }

  puts ("NO");
  return 0;
}
