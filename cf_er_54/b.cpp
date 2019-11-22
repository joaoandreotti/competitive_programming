#include <bits/stdc++.h>

const int MAXN = 1e7;
bool cmp [MAXN];
std::vector <long long> p;

long long isp (long long n) {
  long long sq = sqrt (n);
  for (int i = 0; i < p.size () && (p[i]) <= sq; i++)
    if (n % p[i] == 0)
      return p[i];

  return 1;
}

void sieve () {
  cmp [1] = 1;

  for (int i = 2; i < MAXN; i++) {
    if (!cmp [i]) {
      p.push_back (i);

      for (int j = 2; (i * j) < MAXN; j++) {
        cmp [i * j] = 1;
      }
    }
  }

}

int main () {
  long long n; scanf ("%lld", &n);
  long long ans = 1;
  sieve ();
  long long x = isp (n);

  if (x == 1) {
    printf ("%lld\n", ans);
    return 0;
  }


  n -= x;

  ans += n / 2;

  printf ("%lld\n", ans);

  return 0;
}
