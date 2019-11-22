#include <bits/stdc++.h>

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;

void input ();
void sol (int);

int t;
int n, m;

void input () {
  scanf ("%d", &t);
  for (int i = 1; i <= t; i++) {
    // input
    scanf ("%d%d", &n, &m);
    sol (i);
  }
}

vpi f (int c, int x, int y, vpi p) {
  if (p.size () == (n * m)) {
    puts ("JAMES");
    for (int i = 0; i < p.size (); i++)
      printf ("{%d, %d}\n", p [i].first, p [i].second);
    return p;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vpi aux = p;
      std::sort (aux.begin (), aux.end ());
      auto lb = std::lower_bound (aux.begin (), aux.end (), std::make_pair (i, j));
      int pos = lb - aux.begin ();
      if (i != x && j != y && (x - y) != (i - j) && (x + y) != (i + j) && pos < aux.size () && aux [pos] != std::make_pair (i, j)) {
        puts ("JAMES");
        p.push_back ({i, j});
        aux = f (c + 1, i, j, p);
        if (aux.size ()) {
          return aux;
        }
        p.pop_back ();
      }
    }
  }
  return p;
}

void sol (int cs) {
  printf ("Case #%d: \n", cs);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      vpi dmp;
      vpi ans = f (0, i, j, dmp);
      //puts ("ans: ");
      //for (int i = 0; i < ans.size (); i++)
        //printf ("{%d, %d}\n", ans [i].first, ans [i].second);
    }

}

int main () {
  input ();
  return 0;
}
