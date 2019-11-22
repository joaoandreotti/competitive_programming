#include <bits/stdc++.h>

const int MAXN = 10 + 1;

int n, m;

struct recipe {
  int a = 0, b  = 0, c = 0, d = 0, x = 0;
  
  void init () {
    if (a == 0)
      x = n / c;
    else
      x = std::min (a / b, n / c);
  }
};

bool cmp (const recipe a, const recipe b) {
  //printf ("{%d, %d, %d, %d} = %d, ", a.a, a.b, a.c, a.d, x);
  //printf ("{%d, %d, %d, %d} = %d\n", b.a, b.b, b.c, b.d, y);

  return (a.x*a.d) < (b.x*b.d);
}

recipe arr [MAXN];

int main () {
  scanf ("%d%d", &n, &m);
  arr [0].a = arr [0].b = 0;
  scanf ("%d%d", &arr [0].c, &arr [0].d);

  arr [0].init ();

  for (int i = 1; i <= m; i++) {
    scanf ("%d%d%d%d", &arr [i].a, &arr [i].b, &arr [i].c, &arr [i].d);
    arr [i].init ();
  }


  std::sort (arr, arr + m + 1, cmp);

  /*
  for (int i = 0; i <= m; i++)
    printf ("{%d, %d, %d, %d}", arr [i].a, arr [i].b, arr [i].c, arr [i].d);
  puts ("");
  */

  long long ans = 0;
  for (int i = m; i >= 0; i--) {
    if (n / arr [i].c) {
      if (arr [i].a == 0) {
        ans += (n / arr [i].c) * arr [i].d;
        n = n % arr [i].c;
      }
      else {
        if (arr [i].a / arr [i].b < n / arr [i].c) {
          ans += (arr [i].a / arr [i].b) * arr [i].d;
          n -= (arr [i].a / arr [i].b) * arr [i].c;
        }
        else {
          ans += (n / arr [i].c) * arr [i].d;
          n = n % arr [i].c;
        }
      }
    }
  }

  printf ("%lld\n", ans);

  return 0;
}
