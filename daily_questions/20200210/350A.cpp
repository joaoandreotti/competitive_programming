#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e2 + 1;

int n, m;
int arr [MAXN], brr [MAXN];

void input () {
  scanf ("%d%d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  for (int i = 0; i < m; i++)
    scanf ("%d", brr + i);

  solve ();
}

void solve () {
  int maxn = *std::max_element (arr, arr + n);
  int minn = *std::min_element (arr, arr + n);

  int minm = *std::min_element (brr, brr + m);

  //printf ("maxn: %d, minn: %d, minm: %d\n", maxn, minn, minm);

  if (maxn >= minm || (minn * 2) >= minm)
    puts ("-1");
  else
    printf ("%d\n", std::max (minn * 2, maxn));
}

int main () {
  input ();
  return 0;
}
