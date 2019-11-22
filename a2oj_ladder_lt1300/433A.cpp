#include <bits/stdc++.h>

std::map <int, int> map;

int main () {
  int n;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    map [a]++;
  }
  if (map [100]) {
    if (map [100] % 2 == 0)
      puts ("YES");
    else
      puts ("NO");
  }
  else
    if (map [200] % 2 == 0)
      puts ("YES");
    else
      puts ("NO");
  return 0;
}
