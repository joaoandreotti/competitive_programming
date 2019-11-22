#include <bits/stdc++.h>

std::map <char, int> map;

int main () {
  int n; scanf ("%d", &n);
  std::string str;
  std::cin >> str;
  int x, y; scanf ("%d%d", &x, &y);


  for (int i = 0; i < n; i++)
    map [str [i]]++;

  int posx = 0, posy = 0;

  posx += map ['R'] - map ['L'];
  posy += map ['U'] - map ['D'];

  if ((x + y) > n) {
    puts ("-1");
    return 0;
  }
  else if (posx == x && posy == y) {
    puts ("0");
    return 0;
  }
  else {
  }

  return 0;
}
