#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e2 + 1;

int n;
char str [MAXN];

void input () {
  scanf ("%d", &n);
  scanf ("%s", str);

  solve ();
}

void solve () {
  n *= 2;
  std::sort (str, str + (n / 2));
  std::sort (str + (n / 2), str + n);

  int lt = 1, gt = 1;

  //printf ("str: %s\n", str);

  n /= 2;
  for (int i = 0; i < n; i++) {
    //printf ("(str [%d]: %c | str [%d]: %c) (%d, %d)\n", i, str [i], i + n, str [i + n], lt, gt);

    if (gt && str [i] > str [n + i])
      gt = 1;
    else
      gt = 0;

    if (lt && str [i] < str [n + i])
      lt = 1;
    else
      lt = 0;
  }
  //printf ("(str [%d]: %c | str [%d]: %c) (%d, %d)\n", n, str [n], n + n - 1, str [n + n - 1], lt, gt);

  if (lt || gt)
    puts ("YES");
  else
    puts ("NO");
}

int main () {
  input ();
  return 0;
}
