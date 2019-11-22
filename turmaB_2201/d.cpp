#include <bits/stdc++.h>

int main () {
  int T; scanf ("%d", &T);

  while (T--) {
    long long n1, f1, d1, n2, f2, d2; scanf ("%lld%lld%lld%lld%lld%lld", &n1, &f1, &d1, &n2, &f2, &d2);

    long long f_res = f2 - f1;

    long long px, py;
    for (int i = 0; i <= (int)1e6; i++) {
      long long eq = (((d1 * i) - f_res) / d2);
      if ((d1 * i) - (d2 * eq) == f_res) {
        px = i;
        py = eq;
        break;
      }
    }


    long long px2 = 0, py2;
    int i = px + 1;
    while (!px2) {
      //printf ("%d\n", i);
      long long eq = (((d1 * i) - f_res) / d2);
      //printf ("eq: %lld\n", eq);
      if ((d1 * i) - (d2 * eq) == f_res) {
        px2 = i;
        py2 = eq;
      }
      i++;
    }

    //printf ("px: %lld, px2: %lld, py: %lld\n", px, px2, py);

    long long gx = px2 - px, gy = py2 - py;

    printf ("%lld\n", std::min ((n1 - px - 1) / (gx), (n2 - py - 1) / (gy) ) + 1);
  }
  return 0;
}
