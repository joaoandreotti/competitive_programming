#include <bits/stdc++.h>

void input ();
void solve ();

int n, m;

void input () {
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);
  scanf ("%d%d", &n, &m);

  solve ();
}

void solve () {
  int x = n, y = m;

  if (n > m)
    for (int i = 0; i < n + m; i++)
      if (i % 2) {
        if (y > 0)
          printf ("G");
        else
          printf ("B");
        y--;
      }
      else {
        if (x > 0)
          printf ("B");
        else
          printf ("G");
        x--;
      }
  else
    for (int i = 0; i < n + m; i++)
      if (i % 2) {
        if (x > 0)
          printf ("B");
        else
          printf ("G");
        x--;
      }
      else {
        if (y > 0)
          printf ("G");
        else
          printf ("B");
        y--;
      }

  puts ("");
}

int main () {
  input ();
  return 0;
}
