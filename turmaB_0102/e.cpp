#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef std::map <int, int> mi;
typedef std::vector <int> vi;

int arr [MAXN], bm [MAXN];
vi fp;

int main () {
  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf ("%d", arr + i);
    bm [arr [i]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (!bm [i])
      fp.push_back (i);
  }

  /*
  if (flag) {
    for (int i = 0; i < n; i++)
      printf ("%d ", arr [i]);
    puts ("");
    return 0;
  }
  */


  int k = 0;
  for (int i = 0; i < n; i++) {
    while ((arr [i] > n || bm [arr [i]] > 1) && k < fp.size ()) {
      bm [arr [i]]--;
      arr [i] = fp [k++];
      bm [arr [i]]++;
    }
  }

  //printf ("bm1: %d\n", bm [1]);
  for (int i = 0; i < n; i++) {
    printf ("%d ", arr [i]);
  }
  puts ("");


}
