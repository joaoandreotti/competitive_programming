#include <bits/stdc++.h>

std::map <int, int> map;

int main () {
  int n;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    map[a]++;
  }
  int count = 1;
  if (!map[0])
    puts ("-1");
  else if (map[5] < 9)
    puts ("0");
  else {
    long long ans = 0;
    for (int i = 0; i < 9; i++)
      printf ("5");
    map[5] -= 9;
    for (int i = 0; i < map[5] - (map[5] % 9); i++) {
      printf ("5");
    }
    for (int i = 0; i < map[0]; i++)
      printf ("0");
    puts ("");
  }
  return 0;
}

