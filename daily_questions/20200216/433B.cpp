#include <bits/stdc++.h>

void input ();
void solve ();

const long long MAXN = 1e5 + 1;

typedef struct seg {
  long long n;
  long long arr [MAXN * 2];

  seg () {}

  seg (long long n) : n (n) {}

  void build () {
    for (long long i = n - 1; i > 0; i--)
      arr [i] = arr [i << 1] + arr [(i << 1) + 1];
  }

  void update (long long p, long long value) { 
    p += n;
    for (arr [p] = value; p > 1; p >>= 1)
      arr [p >> 1] = arr [p] + arr [p ^ 1];
  }

  long long rq (long long l, long long r) { // [L, R[
    long long res = 0;
    l += n;
    r += n;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        res += arr [l++];
      if (r & 1)
        res += arr [--r];
    }

    return res;
  }

} seg;

long long n, m;
seg srt, arr;

void input () {
  scanf ("%d", &n);
  srt.n = n;
  arr.n = n;

  for (long long i = 0, a; i < n && scanf ("%lld", &a); i++)
    srt.arr [i + n] = arr.arr [i + n] = a;

  solve ();
}

void solve () {
  std::sort (srt.arr + n, srt.arr + n + n);
  srt.build ();
  arr.build ();


  /*
  for (int i = 0; i < (2 * n); i++)
    printf ("{%lld}", arr.arr [i]);
  puts ("");

  for (int i = 0; i < (2 * n); i++)
    printf ("{%lld}", srt.arr [i]);
  puts ("");
  */

  scanf ("%lld", &m);
  for (long long i = 0, a, l, r; i < m && scanf ("%lld%lld%lld", &a, &l, &r); i++)
    if (a == 1)
      printf ("%lld\n", arr.rq (l - 1, r));
    else
      printf ("%lld\n", srt.rq (l - 1, r));
}

int main () {
  input ();
  return 0;
}
