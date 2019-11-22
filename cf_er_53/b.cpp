#include <bits/stdc++.h>

int arr_a [2 * (int)1e5], arr_b [2 * (int)1e5];
int bm [(2 * (int)1e5) + 10];

int main () {
  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr_a + i);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr_b + i);


  int pos = 0, pans;
  for (int i = 0; i < n; i++) {
    pans = 0;
    pans = pos;
    if (!bm [arr_b [i]]) {
      for (pos; pos < n; pos++) {
        if (arr_a [pos] == arr_b [i]) {
          printf ("%d ", (pos - pans) + 1);
          pos++;
          break;
        }
        else {
          bm [arr_a [pos]] = 1;
        }
      }
    }
    else {
      printf ("0 ");
    }
  }

  puts ("");

  return 0;
}
