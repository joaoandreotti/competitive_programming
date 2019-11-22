#include <bits/stdc++.h>

const long double PI = acosl (-1);
const long double EPS = 1e-9;

typedef std::pair <int, int> pi;

struct cmp  {
  bool operator () (const pi& a, const pi& b) const {
    long double ar = PI * (a.first * a.first);
    long double br = PI * (b.first * b.first);
    return ((br / (long double)b.second) > (ar / (long double)a.second));
  }
};


int main () {
  int T; scanf ("%d", &T);

  while (T--) {
    std::priority_queue <pi, std::vector <pi>, cmp> pq;
    int n, f; scanf ("%d%d", &n, &f);
    f++;
    pi pie;
    for (int i = 0; i < n; i++) {
      int a; scanf ("%d", &a);
      pq.push ({a, 1});
    }

    int sz = f;
    f -= n;
    //printf ("n: %d\n", n);
    //printf ("f: %d\n", f);
    while (f > 0) {
      pi aux = pq.top ();
      pq.pop ();
      aux.second += 1;
      pq.push (aux);
      f--;
    }
    while (sz) {
      pie = pq.top ();
      pq.pop ();
      //printf ("{%d, %d}\n", pie.first, pie.second);
      sz -= pie.second;
    }

    long double ans = PI * (pie.first * pie.first);
    printf ("%Lf\n", ans / (long double)pie.second);
  }

  return 0;
}
