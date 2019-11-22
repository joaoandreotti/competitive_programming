#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;

int n;
int arr [MAXN];

void input () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);
}

void sol () {
  int count = 0, best = 0;
  for (int i = 0 ; i < (2 * n); i++) {
    if (arr [i % n])
      count++;
    else
      count = 0;
    best = std::max (best, count);
  }

  printf ("%d\n", best);
}

int main () {
  input ();
  sol ();
  return 0;
}
