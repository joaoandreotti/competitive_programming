#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

int n;
int arr [MAXN];

void input () {
  scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  solve ();
}

void solve () {
  // there is a pattern that if the sum of the elements
  // is divisible by n, then all elements could be equal
  // otherwise its always possible to make n - 1 equal elements

  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr [i];

  printf ("%d\n", sum % n == 0 ? n : n - 1);
}

int main () {
  input ();
  return 0;
}
