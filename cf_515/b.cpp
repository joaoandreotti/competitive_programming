#include <bits/stdc++.h>

int n, r; 
int arr [(int)1e3 + 1];
std::vector <int> h;

int f (int pos, int nh, std::bitset <1001> bm = 0) {
  std::bitset <1001> aux = bm;
  if (pos >= h.size ()) {
    if (n > bm.count ())
      return INT_MAX;
    else
      return nh;
  }

  for (int i = h [pos] - r + 1; i <= h[pos] + r + 1; i++) {
    if (i < 1000)
      bm [i] = 1;
  }

  return std::min (f (pos + 1, nh, aux), f (pos + 1, nh + 1, bm));
}

int main () {
  scanf ("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) {
    int a; scanf ("%d", &a);
    if (a) {
      h.push_back (i);
      for (int j = (i - r + 1); j <= (i + r + 1); j++)
        if (j <= n)
          arr [j] = 1;
    }
  }

  for (int i = 1; i <= n; i++)
    printf ("%d ", arr [i]);
  puts ("");
  std::sort (arr + 1, arr + n + 1);
  if (arr [1] == 0) {
    puts ("-1");
    return 0;
  }

  printf ("%d\n", f (0, 0));
  return 0;
}
