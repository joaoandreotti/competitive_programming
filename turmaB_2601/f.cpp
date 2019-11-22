#include <bits/stdc++.h>

typedef std::vector <int> vi;
typedef std::vector <vi> graph;

const int MAXN = 1e6 + 1;

graph g;
int chld [MAXN], visited [MAXN];
int n, k, num_cuts;

int dfs (int x) {
  visited [x] = 1;

  for (int v : g [x]) {
    if (!visited [v]) {
      chld [x]++;
    }
  }

  //printf ("x: %d => nf: %d\n", x, chld [x]);
  for (int v : g [x]) {
    if (!visited [v]) {
      chld [x] += dfs (v);
    }
  }
  //printf ("x: %d => nf: %d\n", x + 1, chld [x]);
  return chld [x];
}

void cuts (int x) {
  visited [x] = 1;
  for (int v : g [x]) {
    if (!visited [v]) {
      if (((chld [v] + 1) % (n / (k + 1)) == 0)) {
        //printf ("v: %d, chl+1: %d, n/(k+1): %d", v, chld [v] + 1, (n / (k + 1)));
        //puts (" -- cuted");
        num_cuts++;
      }
      cuts (v);
    }
    /*
    if ((chld [v] + 1) == (n / (k + 1))) {
      puts ("cuted");
      visited [v];
      chld [x] -= chld [v] + 1;
      chld [v] = 0;
      num_cuts++;
    }
    */
  }
}

int main () {
  while (scanf ("%d", &n) != EOF) {
    int a, b;
    g.clear ();
    g.resize (n);
    memset (chld, 0, n * 4);
    memset (visited, 0, n * 4);

    for (int i = 0; i < (n - 1); i++) {
      scanf ("%d%d", &a, &b);
      g [a - 1].push_back (b - 1);
      g [b - 1].push_back (a - 1);
    }


    dfs (0);
    for (int i = 1; i < n; i++) {
      k = i;
      num_cuts = 0;
      memset (visited, 0, n * 4);
      cuts (0);
      if (num_cuts == k)
        printf ("%d ", k);
    }
    puts ("");
  }

  return 0;
}
