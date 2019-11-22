#include <bits/stdc++.h>

const int MAX = 0x3f3f3f3f, MAXN = 1e5 + 8;

int seg_tree [(((int)pow (2, ceil ((int)log2 (MAXN)))) * 2) - 1];
int arr [MAXN];

int build (int i, int j, int pos) {
  printf ("i: %d, j:%d\n", i, j);
  if (i >= j) { // entao o range eh o propio elemento
    puts ("aaaaaaa");
    seg_tree [pos] = arr [i];
    return arr [i];
  }
  else {
    int left = (pos*2), right = (pos*2) + 1;
    int mid = (j - i) / 2;

    seg_tree [pos] = build (i, mid, left) + build (mid + 1, j, right);
    return seg_tree [pos];
  }
}

int main () {
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;
  arr[4] = 5;
  arr[5] = 6;
  arr[6] = 7;
  build (1, 6, 1);
  for (int i = 1; i <= 6; i++)
    printf ("%d ", seg_tree [i]);
  puts ("");
  return 0;
}
