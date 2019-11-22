#include <bits/stdc++.h>
#define int long long

const int MAXN = 1e5 + 1, INF = 0x3f3f3f3f;

int n, k;
int arr [MAXN];

/* TLE
int f (int pos, int pts) {
  if (pos > n)
    return INF;

  if (pos == n)
    if (pts >= k)
      return 0;
    else
      return arr [pos];


  int ans = INF;

  ans = std::min (ans, f (pos + 1, pts + 1) + arr [pos]);
  if (pts >= k)
    ans = std::min (ans, f (pos + 1, pts - k));

  return ans;
}
*/

int f () {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += arr [i];

  std::priority_queue <int> pq;

  int pts = 0;
  for (int i = 1; i <= n; i++) {
    if (!(i % (k + 1)))
      pts++;

    if (pts)
      if (pts - pq.size ())
        pq.push (- arr [i]);
      else if (((-1) * pq.top ()) < arr [i]) {
        pq.pop ();
        pq.push (- arr [i]);
      }
  }

  while (!pq.empty ()) {
    ans -= (-1) * pq.top ();
    pq.pop ();
  }

  return ans;
}

int32_t main () {
  while (scanf ("%lld%lld", &n, &k) != EOF) {
    for (int i = 1; i <= n; i++)
      scanf ("%lld", arr + i);

    int ans = f ();
    printf ("%lld\n", ans);
  }
  return 0;
}
