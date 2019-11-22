#include <bits/stdc++.h>

const int MAXN = 1e5 + 1;
int n;
int arr [MAXN * 2];

// ***** RANGE SUM QUERY *****

// use arr as the seg_tree and the input array
// all positions from N to 2 * N are already filled with the leaf values
void build () {
  for (int i = n - 1; i > 0; i--)
    arr [i] = arr [i << 1] + arr [(i << 1) + 1];
}

void update (int p, int value) { 
  p += n; // p + n == leaf nodes indexs
  // arr [p] = value == updating the leaf index
  // arr [p >> 1] == father node
  // arr [p] + arr [p ^ 1] == pair that have the same father (odd and even number)
  for (arr [p] = value; p > 1; p >>= 1)
    arr [p >> 1] = arr [p] + arr [p ^ 1];
}

int rq (int l, int r) { // [L, R[
  int res = 0;
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

int main () {
  scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i + n);

  build ();
  puts ("printing the tree:");
  for (int i = 1; i < 2 * n; i++)
    printf ("%d ", arr [i]);
  puts ("");


  printf ("rq [1, 2]: %d\n", rq (3, 8));
  return 0;
}
