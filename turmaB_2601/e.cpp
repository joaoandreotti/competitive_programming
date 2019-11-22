#include <bits/stdc++.h>

const int MAXN = 5e4 + 1;

int rank [MAXN], set_size [MAXN], p [MAXN], can_eat [MAXN], eaten_by [MAXN];

int find (int a) {
  return p [a] == a ? a : p[a] = find (p[a]);
}

int same_set (int a, int b) {
  return find (a) == find (b);
}

int check_eat (int a, int b) {
  a = find (a);
  b = find (b);
  if (can_eat [a] == b || can_eat [b] == a)
    return 1;
  if (eaten_by [a] == b || eaten_by [b] == a || eaten_by [a] == p[b] || eaten_by [b] == p[a])
    return 1;
  return 0;
}

void union_find (int a, int b) {
  if (!same_set (a, b)) {
    a = find (a);
    b = find (b);

    if (rank [a] > rank [b]) {
      p [b] = a;
      can_eat [a] = can_eat [b];
      eaten_by [a] = eaten_by [b];
      set_size [a] += set_size [b];
    }
    else {
      p [a] = b;
      can_eat [b] = can_eat [a];
      eaten_by [b] = eaten_by [a];
      set_size [b] += set_size [a];
      if (rank [a] == rank [b])
        rank [b]++;
    }
  }
}


int main () {
  int T; scanf ("%d", &T);
  while (T--) {
    int n, q; scanf ("%d%d", &n, &q);
    memset (rank, 0, n * 4);
    memset (can_eat, 0, n * 4);
    memset (eaten_by, 0, n * 4);
    for (int i = 1; i <= n; i++) {
      set_size [i] = 1;
      p [i] = i;
    }

    int a, b, c;
    int ans = 0;
    for (int i = 0; i < q; i++) {
      scanf ("%d%d%d", &a, &b, &c);
      //printf ("a: %d, b: %d, c: %d\n", a, b, c);
      if (b > n || c > n) {
        //printf ("false: %d\n", i+ 1);
        ans++;
      }
      else {
        same_set (b, c);
        if (a == 1) {
          if (check_eat (b, c)) {
            //printf ("false: %d\n", i+ 1);
            ans++;
          }
          else
            union_find (b, c);
        }
        else {
          ////printf ("eaten_by [%d]: %d, p [%d]: %d\n", c, eaten_by [c], b, p [b]);
          if (same_set (b, c)) {
            //puts ("1");
            //printf ("false: %d\n", i+ 1);
            ans++;
          }
          else if (eaten_by [b] == p [c]) {
            //puts ("2");
            //printf ("false: %d\n", i+ 1);
            ans++;
          }
          else {
            //puts ("3");
            can_eat [b] = p [c];
            eaten_by [p[c]] = b;
          }
        }
      }

      /*
      puts ("p:");
      for (int i = 1; i <= n; i++) {
        printf ("p [%d]: %d\n", i, p[i]);
      }
      puts ("\n----");

      puts ("can_eat:");
      for (int i = 1; i <= n; i++) {
        printf ("can_eat [%d]: %d\n", i, can_eat[i]);
      }
      puts ("\n----");

      puts ("eaten_by:");
      for (int i = 1; i <= n; i++) {
        printf ("eaten_by [%d]: %d\n", i, eaten_by[i]);
      }
      puts ("\n----");
      */
    }

    printf ("%d\n", ans);

  }
  return 0;
}
