#include <bits/stdc++.h>

const int deg = 6;

int h, m, n;
std::set <double> ang;

int main () {
  h = 0; m = 0;
  for (int i = 0; i <= 720; i++) {
    ang.insert (abs (h - m) * deg);
    m++;
    if (!(m % 12))
      h++;
  }

  while (scanf ("%d", &n) != EOF) {
    if (ang.find (n) != ang.end ()) 
      puts ("Y");
    else
      puts ("N");
  }

  return 0;
}
