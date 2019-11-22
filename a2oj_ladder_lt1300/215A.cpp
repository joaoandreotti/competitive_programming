#include <bits/stdc++.h>

std::map <int, int> map;

int main () {
  int n, m;
  scanf ("%d", &n);
  int pedal[n];
  for (int i = 0; i < n; i++)
    scanf ("%d", pedal + i);
  scanf ("%d", &m);
  int rear[m];
  for (int i = 0; i < m; i++)
    scanf ("%d", rear + i);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!(rear [j] % pedal [i]))
        map [rear [j] / pedal [i]]++;

  printf ("%d\n", map.rbegin ()->second);

  return 0;
}
