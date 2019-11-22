#include <bits/stdc++.h>

int arr [101];
int usd [101];

int main () {
  int n, k; scanf ("%d%d", &n, &k);

  int ca = 0, cb = 0;
  for (int i = 1; i <= n; i++) {
    scanf ("%d", arr + i);
    if (arr [i] == 1)
      ca++;
    else
      cb++;
  }

  int ans = 0;
  for (int b = 1; b <= n; b++) {
    int aa = ca, ab = cb;
    int c = 0;
    memset (usd, 0, sizeof (usd));
    for (int i = (0-n); i <= n; i++) {
      c = b + (i * k);
      if (c >= 1 && c <= n) {
        if (!usd [c]) {
          if (arr [c] == 1)
            aa--;
          else
            ab--;
          usd [c] = 1;
        }
      }
    }
    ans = std::max (ans, abs (aa - ab));
  }

  printf ("%d\n", ans);
  return 0;
}
