#include <bits/stdc++.h>

std::map <int, long long> map;
int arr [2 * (int)1e5];

int main () {
  int n, k;
  scanf ("%d%d", &n, &k);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  std::sort (arr, arr + n);

  int lp = 0;
  for (int i = 0; i < n - 1; i++) {
    if (arr [i] != arr [i + 1]) {
      lp = i + 1;
      break;
    }
  }

  for (int i = lp; i < n; i++)
    map [arr [i] - arr [0]]++;

  long long sum = 0, ans = 0;;
  for (auto i = map.rbegin (); i != map.rend (); i++) {
    sum += i->second * i->first;

    printf ("sum: %lld\n", sum);
    printf ("st: %d, nd: %d\n", i->first, i->second);
    if (sum > k) {
      sum = 0;
      ans++;
    }
  }

  printf ("sum: %lld\n", sum);
  
  printf ("%lld\n", ans);



  return 0;
}
