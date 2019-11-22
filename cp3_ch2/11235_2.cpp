#include <bits/stdc++.h>

const int MAXN = 1e5 + 1;
int n;
int input [MAXN], count [2 * MAXN], start [MAXN];
typedef std::pair <std::pair <int, int>, std::pair <int, std::pair <int, int>> > pip;
std::vector <pip > v;
#define ff first.first //  maior esq
#define fs first.second //  quantos tem esq
#define sf second.first //  maior dir
#define ssf second.second.first //  quantos tem dir
#define sss second.second.second //  maior de todo


pip cmp (pip a, pip b) {
  pip c;

  if (a.ff == -111111)
    return b;
  if (b.ff == -111111)
    return a;

  if (a.ff == a.sf && b.ff == b.sf) {
    c.ff = a.ff;
    c.fs = a.fs + a.ssf;

    c.sf = b.ff;
    c.ssf = b.fs + b.ssf;

    if (a.sf == b.ff)
      c.sss = c.fs + c.ssf;
    else
      c.sss = std::max (c.fs, c.ssf);
  }
  else if (a.ff == a.sf && b.ff != b.sf) {
    c.ff = a.ff;
    c.fs = a.fs + a.ssf;

    c.sf = b.sf;
    c.ssf = b.ssf;

    if (a.sf == b.ff)
      c.sss = c.fs + b.fs;
    else
      c.sss = std::max (c.fs, c.ssf);
  }
  else if (a.ff != a.sf && b.ff == b.sf) {
    c.ff = a.ff;
    c.fs = a.fs;

    c.sf = b.ff;
    c.ssf = b.fs + b.ssf;

    if (a.sf == b.ff)
      c.sss = a.ssf + c.ssf;
    else
      c.sss = std::max (c.fs, c.ssf);
  }
  else if (a.ff != a.sf && b.ff != b.sf) {
    c.ff = a.ff;
    c.fs = a.fs;

    c.sf = b.sf;
    c.ssf = b.ssf;

    if (a.sf == b.ff)
      c.sss = std::max (a.ssf + b.fs, std::max (c.fs, c.ssf));
    else
      c.sss = std::max (c.fs, c.ssf);
  }

  return c;
}

void build () {
  for (int i = n - 1; i > 0; i--)
    v [i] = cmp (v [i << 1], v [(i << 1) + 1]);
}

int rq (int l, int r) { // [L, R[
  //pip res = {{-111111, 0}, {-111111, {0, 0}}};
  int res = 0;
  l += n;
  r += n;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res += v [l++].sss;
    if (r & 1)
      res += v [--r].sss;
  }

  return res;
}

int main () {
  int q;
  scanf ("%d%d", &n, &q);
  printf ("%d, %d\n", n, q);

  v.resize (MAXN * 2);

  for (int i = 0; i < n; i++)
    scanf ("%d", input + i);


  for (int i = 0; i < n; i++)
    v [i + n] = {{input [i], 1}, {input [i], {1, 1}}};

  
  for (int i = n; i < (2*n); i++)
    printf ("{{%d, %d}, {%d, {%d, %d}}}\n", v[i].ff, v[i].fs, v[i].sf, v[i].ssf, v[i].sss);

  build ();

  for (int i = 0; i < (2*n); i++)
    printf ("%d: {{%d, %d}, {%d, {%d, %d}}}\n", i, v[i].ff, v[i].fs, v[i].sf, v[i].ssf, v[i].sss);

  /*
  pip ans = rq (0, 10);
  printf ("rq: {{%d, %d}, {%d, {%d, %d}}}\n", ans.ff, ans.fs, ans.sf, ans.ssf, ans.sss);
  */
  int ans = rq (0, 7);
  printf ("%d\n", ans);

  return 0;
}
