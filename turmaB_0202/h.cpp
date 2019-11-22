#include <bits/stdc++.h>

const int MAXN = 2e5 + 1;

#define LSOne(x) (x & (-x))

typedef std::vector <int> vi;
vi ft [MAXN];
int n, q, arr [MAXN];
std::map <int, int> map;

void insert (int i, int v) {
  //printf ("pos: %d, value: %d\n", i, v);
  for (; i < ft [v].size (); i += LSOne (i)) {
    ft [v][i] += 1;
  }
}

void update (int i, int v, int x) {
  for (; i <= ft [v].size (); i += LSOne (i)) {
    ft [v][i] += x;
  }
}

int rsq(int i, int v) {
  int sum = 0;
  for (; i; i -= LSOne(i)) {
    sum += ft[v][i];
  }
  return sum; 
}

int main () {
  scanf ("%d%d", &n, &q);
  for (int i = 1; i <= n; i++)
    ft[i].resize (n + 1);

  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    int a; scanf ("%d", &a);
    arr [i] = a;

    if (!map [a]) map [a] = cnt++;

    insert (i, map [a]);
  }

  for (int i = 1; i <= q; i++) {
    int a, b; scanf ("%d%d", &a, &b);

    if (!map [b]) map [b] = cnt++;

    update (a + 1, , -1);
    update (a + 1, map [b], 1);
  }

  for (int i = 1; i <= n; i++) {
    printf ("i: %d =>", i);
    for (int j = 1; j < ft [i].size (); j++)
      printf (" %d", ft [i][j]);
    puts ("");
  }


  return 0;
}
