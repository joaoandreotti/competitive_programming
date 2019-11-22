#include <bits/stdc++.h>

const int MAXN = 2e5 + 1;
int st [2 * MAXN];
int n;

void build () {
  for (int i = n - 1; i > 0; i--)
    st [i] = st [i << 1] + st [(i << 1) + 1];
}

void update (int i, int v) {
  i += n;
  for (st [i] = v; i > 1; i >>= 1)
    st [i >> 1] = st [i] + st [i ^ 1];
}

int rsq (int l, int r) {
  int res = 0;
  l += n;
  r += n;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res += st [l++];
    if (r & 1)
      res += st [--r];
  }

  return res;
}

int main () {
  char op [5];
  int cs = 1;

  while (scanf ("%d", &n) && n != 0) {
    if (cs > 1)
      puts ("");
    printf ("Case %d:\n", cs++);
    memset (st, 0, sizeof (st));

    for (int i = n; i < (n * 2); i++)
      scanf ("%d", st + i);

    build ();
    /*
    puts ("tree: ");
    for (int i = 0; i < (n * 2); i++)
      printf ("%d ", st [i]);
    puts ("");
    */

    int a, b;
    while(scanf ("%s", op) && op [0] != 'E') {
      scanf ("%d%d", &a, &b);
      if (op [0] == 'M') {
        printf ("%d\n", rsq (a - 1, b));
      }
      else if (op [0] == 'S') {
        update (a - 1, b);
      }
    }
  }
  return 0;
}
