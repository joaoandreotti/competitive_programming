#include <bits/stdc++.h>

int arr [(int)1e5 + 1];
std::vector <int> v;

int main () {
  int n, k;
  scanf ("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf ("%d", arr + i);
    if (i > 0)
      arr [i] += arr [i - 1];
  }
  int div;
  if ((arr [n - 1] % k) == 0)
    div = arr [n - 1] / k;
  else {
    puts ("No");
    return 0;
  }
  int x = 1, sum = 0;
  for (int i = 0; i < n; i++) {
    if ((arr [i]) == div * x) {
      v.push_back ((i + 1) - sum);

      sum += v [v.size () - 1];

      x++;
    }
  }

  if (v.size () == k && sum == n) {
    puts ("Yes");
    for (int i = 0; i < v.size (); i++)
      if (i + 1 < v.size ())
        printf ("%d ", v [i]);
      else
        printf ("%d\n", v [i]);
  }
  else
    puts ("No");


  return 0;
}
