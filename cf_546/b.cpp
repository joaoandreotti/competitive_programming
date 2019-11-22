#include <bits/stdc++.h>

const int MAXN = 5e3 + 1;

int n, k;
int cnt, te, end;
int arr [MAXN];

int main () {
  scanf ("%d%d", &n, &k);

  if (k <= (n / 2))
    cnt = k - 1;
  else
    cnt = n - k;

  te = (n - 1) * 2;
  end = n + 1;

  printf ("%d\n", cnt + te + end + 1);

  return 0;
}
