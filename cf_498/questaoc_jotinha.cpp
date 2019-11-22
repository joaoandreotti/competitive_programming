#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  int e = 0, d = n - 1;
  long long unsigned es = 0, ds = 0;

  long long unsigned ans = 0;
  //printf ("es: %d, ds: %d\n", es, ds);
  es += arr[e];
  ds += arr[d];
  while (e < d) {
    //printf ("e: %d, d: %d\n", e, d);
    if (es == ds)
      ans = std::max (ans, es);

    if (es < ds)
      es += arr[++e];
    else if(es > ds)
      ds += arr[--d];
    else {
      es += arr[++e];
      ds += arr[--d];
    }
    //printf ("es: %d, ds: %d\n", es, ds);
  }
  printf ("%llu\n", ans);
  return 0;
}
