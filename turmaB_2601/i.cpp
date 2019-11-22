#include <bits/stdc++.h>

const int MAXN = 1e5 + 1;

int arr_a [MAXN], arr_b [MAXN];

int main () {
  int n, m; scanf ("%d%d", &n, &m);
  long long maxA = 0, maxB = 0, minB = INT_MAX;

  for (int i = 0; i < n; i++)
    scanf ("%d", arr_a + i);

  for (int i = 0; i < m; i++) {
    scanf ("%d", arr_b + i);
    maxB = std::max (maxB, (long long)arr_b [i]);
    minB = std::min (minB, (long long)arr_b [i]);
  }

  int count = 0;
  for (int i = 0; i < m; i++) {
    if (maxB == arr_b [i])
      count++;
  }

  for (int i = 0; i < n; i++)
    if (maxA <= arr_a [i] && arr_a [i] <= maxB)
      maxA = arr_a [i];

  if (maxA == 0) {
    puts ("0");
    return 0;
  }

  long long ans_1 = std::min ((maxB - maxA), maxB - minB);
  long long aux = maxB - ans_1;
  ans_1 *= count;
  for (int i = 0; i < n; i++) {
    if (arr_a [i] < aux)
      ans_1 += aux - arr_a [i];
  }

  long long ans_2 = 0;
  for (int i = 0; i < n; i++) {
    if (arr_a [i] < maxB)
      ans_2 += maxB - arr_a [i];
  }



  printf ("%lld\n", std::min (ans_1, ans_2));

}
