#include <bits/stdc++.h>

#define EPS 1e-9

void input ();
void solve ();

int t;
int n, p;

void input () {
  scanf ("%d", &t);
  for (int j = 0; j < t; j++) {
    p = 0;
    scanf ("%d", &n);
    n++;

    for (int i = 0, b; i < 4 && scanf ("%d", &b); i++)
      p += b;

    solve ();
  }
}

void solve () {
  if ((p * 2) >= n)
    puts ("Yes");
  else
    puts ("No");
}

int main () {
  input ();
  return 0;
}
