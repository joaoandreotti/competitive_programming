#include <bits/stdc++.h>

#define LSOne(x) (x & (-x))
const int MAXN = 2e5 + 10;

typedef std::vector <int> vi;
vi ft;
int arr [MAXN];
int n;

void insert (int i, int v, int flag) {
  int x = i;
  int upd;
  if (flag)
    upd = arr [i];
  else
    upd = 0;
  arr [i] = v;

  for (; i <= ft.size (); i += LSOne (i)) {
    ft [i] -= upd;
    ft [i] += v;
  }
}

int rsq (int j) {
  int sum = 0;

  for (; j; j -= LSOne (j))
    sum += ft [j];

  return sum;
}

int main () {
  char op [5];
  int cs = 1;
  while (scanf ("%d", &n) && n != 0) {
    if (cs > 1)
      puts ("");
    //printf ("n: %d\n", n);
    printf ("Case %d:\n", cs++);
    ft.clear ();
    ft.assign (n + 1, 0);

    for (int i = 1; i <= n; i++) {
      scanf ("%d", arr + i);
      insert (i, arr [i], 0);
    }

    /*
    puts ("printing ft: ");
    for (int i = 1; i <= n; i++)
      printf ("%d ", ft [i]);
    puts ("");
    */

    int a, b;
    while(scanf ("%s", op) && op [0] != 'E') {
      scanf ("%d%d", &a, &b);
      //puts ("aa");
      //printf ("op: %s, a: %d, b: %d\n", op, a, b);
      if (op [0] == 'M') {
        if (a == 1)
          printf ("%d\n", rsq (b));
        else
          printf ("%d\n", rsq (b) - rsq (a - 1));
      }
      else {
        insert (a, b, 1);
        /*
        puts ("printing ft: ");
        for (int i = 1; i <= n; i++)
          printf ("%d ", ft [i]);
        puts ("");
        */
      }
    }
    //printf ("op: %s\n", op);
  }
  return 0;
}
