#include <bits/stdc++.h>

const int MAXN = 1e5 + 1;

typedef std::pair <int, int> pi;

int n, f, maxp, sum;
int fnd [MAXN];
int visited [MAXN];

std::vector <std::vector <pi>> lm, ud;
std::vector <int> leafs;

void dfs (int x, int val) {

  if (fnd [x]) {
    //printf ("val: %d\n", val);
    maxp = std::max (val, maxp);
  }

  visited [x] = 1;

  for (pi n : lm [x]) {
    if (!visited [n.first])
      dfs (n.first, n.second + val);
  }
}

int ldfs (int x) {
  //printf ("fnd [%d]: %d\n", x, fnd [x]);
  visited [x] = 1;
  for (pi n : ud [x]) {
    if (!visited [n.first])
      return ldfs (n.first) + n.second;
    else
      return n.second;
  }

  return 0;
}

int main () {

  while (scanf ("%d%d", &n, &f) != EOF) {
    lm.clear ();
    ud.clear ();
    ud.resize (n + 1);
    lm.resize (n + 1);
    leafs.clear ();
    memset (visited, 0, (n + 1) * 4);
    memset (fnd, 0, sizeof (fnd));
    sum = 0;
    maxp = 0;

    for (int i = 2; i <= n; i++) {
      int a, b, c; scanf ("%d%d%d", &a, &b, &c);
      lm [a].push_back ({b, c});
      ud [b].push_back ({a, c});
    }

    for (int i = 0; i < f; i++) {
      int a; scanf ("%d", &a);
      fnd [a] = 1;
      leafs.push_back (a);
    }

    dfs (1, 0);
    //puts ("-------");

    memset (visited, 0, (n + 1) * 4);

    printf ("maxp: %d\n", maxp);
    for (int i = 0; i < leafs.size (); i++) {
      printf ("leafs: %d\n", leafs [i]);
      if (!visited [leafs [i]])
        sum += ldfs(leafs [i]);
      printf ("sum: %d\n", sum);
    }
    
    printf ("%d\n", std::max (sum - maxp, 0));


  }
  return 0;
}
