#include <bits/stdc++.h>

const int MAXN = 2e5 + 1;

long long n, m, k;
long long arr [MAXN];

int main () {
  scanf ("%lld%lld%lld", &n, &m, &k);

  for (int i = 0; i < n; i++)
    scanf ("%lld", arr + i);

  std::sort (arr, arr + n);

  long long lst = arr [n - 1];
  long long fst = arr [n - 2];

  if (m == k)
    printf ("%lld\n", lst * m);
  else {
    long long tms = m / k;
    tms = std::max ((long long) 1, tms - 1);
    long long ans = 0;

    long long use = (tms * k) + tms;
    ans += tms * k * lst;
    ans += (m - (tms * k)) * fst;
    //ans += (m - use) * lst;


    printf ("%lld\n", ans);
  }


  return 0;
}
