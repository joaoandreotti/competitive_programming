#include <bits/stdc++.h>

const int MAXN = 5e4 + 1;

int n;
int arr [MAXN];

int maxd = 1, px = 0, py = 0;
int msq;
long long bfr = 0, ans = INT_MAX;

long long f (int i, int j) {
  long long r = arr [j] - (arr [j] / i);
  long long r1 = (arr [0] * i) - arr [0];
  //printf ("r1: %lld, r: %lld\n", r1, r);
  long long aux = bfr + (r1-r);
  return aux;
}

int main () {
  scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf ("%d", arr + i);
    bfr += arr [i];
  }
  std::sort (arr, arr + n);

  for (int i = 2; i <= 100; i++)
    for (int j = 1; j < n; j++)
      if (!(arr [j] % i)) {
        ans = std::min (ans, f (i, j));
        //printf ("ans: %d, i: %d, j: %d\n", ans, i, j);
      }


  //printf ("maxd: %d, px: %d, py: %d\n", maxd, px, py);
  printf ("%lld\n", std::min (ans, bfr));
  return 0;
}
