#include <bits/stdc++.h>


int main () {
  int n, k;
  scanf ("%d%d", &n, &k);
  int num[n];
  int len[n];
  for (int i = 0; i < n; i++) len[i] = 0;
  for (int i = 0; i < n; i++) scanf ("%d", &num[i]);

  std::vector <int> memo [11];
  long long vr[11];
  vr [0] = 1;
  for (int i = 0; i < 10; i++) {
    vr[i+1] = (vr[i] * 10) % k;
  }

  for (int i = 0; i < n; i++) {
    int x = num[i];
    while (x > 0) {
      x /= 10;
      len[i]++;
    }
    printf ("len[%d]: %d, num[%d]: %d, %d mod %d: %d\n", i, len[i], i, num[i], num[i], k, num[i] % k);
    memo [len[i]].push_back ((num[i]) % k);
  }

  for (int i = 0; i < 11; i++)
    std::sort (memo[i].begin (), memo[i].end ());

  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < memo[i].size (); j++)
      printf ("%d ", memo[i][j]);
    printf ("\n");
  }

  long long unsigned res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 11; j++) {
      int r = (num[i] * vr[j]) % k;
      int xr = (k - r) % k;
      auto lb = std::lower_bound (memo[j].begin (), memo[j].end (), xr);
      auto ub = std::upper_bound (memo[j].begin (), memo[j].end (), xr);
      res += ub - lb;
      if (len[i] == j && ((r + num[i] % k) % k == 0))
        res--;
      printf ("num[%d]: %d, r: %d, xr: %d, res: %llu\n", i, num[i], r, xr, res);
    }
  }

  std::cout << res << '\n';



  return 0;
}
