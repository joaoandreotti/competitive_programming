#include <bits/stdc++.h>

const int MAXN = 1e3 + 1;

int rank [MAXN], p [MAXN];
int ans [MAXN];

int find (int a) {
  if (p [a] == a)
    return a;
  return p[a] = find (p [a]);
}

int same (int a, int b) {
  return find (a) == find (b);
}

void uf (int a, int b) {
  if (!same (a, b)) {
    a = find (a);
    b = find (b);
    if (rank [a] > rank [b])
      p [b] = a;
    else {
      p [a] = b;
      if (rank [a] == rank [b])
        rank [b]++;
    }
  }
}

std::vector <int> arr [MAXN];

int main () {
  int n, m; scanf ("%d%d", &n, &m);

  int flag = 0;
  for (int i = 0; i < n; i++) {
    int a, b; scanf ("%d", &a);
    if (a)
      flag = 1;
    for (int j = 0; j < a; j++) {
      scanf ("%d", &b);
      arr [i].push_back (b);
    }
    std::sort (arr [i].begin (), arr [i].end ());
  }

  if (!flag) {
    printf ("%d\n", n);
    return 0;
  }

  for (int i = 0; i <= n; i++)
    p [i] = i;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < arr [i].size (); j++) {
      for (int k = 0; k < n; k++) {
        if (k != i && !same (i, k)) {
          auto l = std::lower_bound (arr [k].begin (), arr [k].end (), arr[i][j]);
          if (l != arr [k].end () && (*l) == arr [i][j]) {
            //printf ("l: %d, uf: {%d, %d}\n", arr [i][j],i, k);
            uf (i, k);
          }
        }
      }
    }
  }

  //puts ("p:");
  for (int i = 0; i < n; i++) {
    //printf ("%d ", p [i]);
    ans [p[i]] = 1;
  }
  //puts ("");

  long long count = 0;
  for (int i = 0; i < n; i++) {
    if (ans [i])
      count++;
  }

  /*
  puts ("ans:");
  for (int i = 0; i < n; i++) {
    printf ("%d ", ans [i]);
  }
  puts ("");
  */

  printf ("%lld\n", count - 1);

  return 0;
}
