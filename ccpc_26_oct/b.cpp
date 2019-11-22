#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 1e5 + 1;

int n, m;
int stations [MAXN];
vvi g;

void input () {
  scanf ("%d%d", &n, &m);
  g.resize (n);
  for (int i = 0; i < n; i++)
    scanf ("%d", stations + i);

  for (int i = 0, a, b; i < m && scanf ("%d%d", &a, &b); i++) {
    g [--a].push_back (--b);
    g [b].push_back (a);
  }

  solve ();
}

void solve () {
  int zero = 0, one = 0;

  for (int i = 0; i < n; i++)
    if (stations [i])
      one++;
    else
      zero++;

  for (int i = 0; i < n; i++) {
    long long sum = 0;
    int count = 0;
    int nc = n - 1;

    printf ("not counted: %d\n", nc);

    // all stations of distance one
    for (int v : g [i])
      if (stations [v] != stations [i])
        count++;

    //printf ("count: %d\n", count);
    if (stations [i])
      sum += (one - 1) - (g [i].size () - count) + count;
    else
      sum += (zero - 1) - (g [i].size () - count) + count;

    nc -= sum;

    printf ("not counted: %d\n", nc);
    //printf ("sum one: %lld\n", sum);

    // all stations of distance two
    if (count) {
      if (stations [i]) {
        sum += 2 * (zero - count);
        nc -= (zero - count);
      }
      else {
        sum += 2 * (one - count);
        nc -= (one - count);
      }
    }
    printf ("not counted: %d\n", nc);

    //printf ("sum two: %lld\n", sum);

    // all stations of distance three

    sum += 3 * nc;

    //printf ("sum three: %lld\n", sum);

    if (i + 1 < n)
      printf ("%lld ", sum);
    else
      printf ("%lld\n", sum);
  }


}

int main () {
  input ();
  return 0;
}
