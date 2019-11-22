#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e3 + 1;

int t, n;
std::string str;

void input () {
  scanf ("%d", &t);

  for (int i = 0; i < t; i++) {
    scanf ("%d", &n);
    std::cin >> str;
    solve ();
  }
}

void solve () {
  int i;
  for (i = n; i > 0; i--)
    if (str [i - 1] == '1')
      break;
  int x = 2 * i;

  for (i = 0; i < n; i++)
    if (str [i] == '1')
      break;
  int y = 2 * (n - i);

  printf ("%d\n", std::max ({n, x, y}));
}

int main () {
  input ();
  return 0;
}
