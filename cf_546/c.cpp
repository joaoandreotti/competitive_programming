#include <bits/stdc++.h>

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 5e2 + 1;

int n, m;
vvi ara, arb;

bool check (vvi ara, vvi arb) {
  for (int i = 0; i < n; i++)
    if (ara [i][0] != arb [i][0])
      return false;

  for (int i = 0; i < n; i++)
    if (ara [0][i] != arb [0][i])
      return false;

  return true;
}

vvi trnsp (int x1, int y1, int x2, int y2) {
  vvi ans;
  ans.resize (abs (x1 - x2));
  for (int i = 0; i < ans.size (); i++)
    ans [i].resize (abs (y1 - y2));

  for (int i = 0; i < ans.size (); i++)
    for (int j = 0; j < ans [i].size (); j++)
      ans [i][j] = ara [j + y1][i + x1];

  return ans;
}

bool f (vvi a) {


  vvi aux;
  if (check (a, arb)) {
    aux.resize (a.size () - 1);
    for (int i = 1; i < a.size (); i++) {
      aux [i].resize (a [i].size () - 1);
      for (int j = 1; j < a [i].size (); j++)
        aux [i - 1][j - 1] = a [i][j];
    }
    return f (aux);
  }
  else {
    int x = std::min (a.size (), a [0].size ());
    aux = trnsp (0, 0, x, x);
    return f (aux);
  }
}


int main () {
  scanf ("%d%d", &n, &m);

  ara.resize (n);
  arb.resize (n);
  for (int i = 0; i < n; i++) {
    ara [i].resize (m);
    for (int j = 0; j < m; j++)
      scanf ("%d", &ara [i][j]);
  }
  for (int i = 0; i < n; i++) {
    arb [i].resize (m);
    for (int j = 0; j < m; j++)
      scanf ("%d", &arb [i][j]);
  }

  return 0;
}
