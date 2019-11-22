#include <bits/stdc++.h>

const int MAXN = 5e5 + 1;

int h [MAXN];

int main () {
  int n, m; 

  for (int i = 1; i <= MAXN; i++) {
    int flag = 0;
    int aux = i;
    int rep [10];
    memset (rep, 0, sizeof (rep));
    while (aux) {
      rep [aux % 10]++;
      aux /= 10;
    }
    for (int j = 0; j < 10; j++) {
      if (rep [j] > 1)
        flag = 1;
    }
    if (!flag)
      h [i] = 1;
  }
  while (scanf ("%d%d", &n, &m) != EOF) {
    int ans = 0;
    for (int i = n; i <= m; i++) {
      if (h [i])
        ans++;
    }

    printf ("%d\n", ans);
  }
  return 0;
}
