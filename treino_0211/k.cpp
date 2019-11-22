#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

int n, k;
int arr [MAXN];

void input () {
  scanf ("%d%d", &n, &k);
  solve ();
}

void solve () {
  int flag = 1;
  int last = -1;
  for (int i = 1; i <= n; i++)
    if (i % k)
      arr [i] = 1;

  for (int i = 1; i <= n; i++)
    printf ("%d ", arr [i]);
  puts ("");
  if (arr [n])
    puts ("Peter");
  else
    puts ("Vinicius");
}

int main () {
  input ();
  return 0;
}
