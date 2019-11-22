#include <bits/stdc++.h>

int arr [(int)1e3 + 1], x [(int)1e3 + 1];
std::vector <int> v;

int main () {
  int n; scanf ("%d", &n);

  arr [0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf ("%d", arr + i);
  }


  for (int i = 1; i <= n; i++) {
    memset (x, -1, sizeof (x));
    int flag = 1;

    //printf ("size: %d\n", i);
    for (int j = 1; j <= n; j++) {
      //printf ("j: %d, x[%d] = %d | arr [j] - arr [j - 1]: %d\n", j - 1, (j - 1) % i, x [(j - 1) % i], arr [j] - arr [j - 1]);
      if (x [(j - 1) % i] == -1) {
        x [(j - 1) % i] = abs (arr [j] - arr [j - 1]);
      }
      else {
        //printf ("x: %d --- (arr [%d] - arr [%d]): %d\n", x [(j - 1) % i], j, j - 1, (arr [j] - arr [j - 1]));
        if (x [(j - 1) % i] != abs (arr [j] - arr [j - 1])) {
          flag = 0;
          break;
        }
      }
    }

    if (flag)
      v.push_back (i);

    /*
    puts ("");

    for (int j = 0; j < i; j++) {
      printf ("%d ", x [j]);
    }
    puts ("");
     */
  }

  printf ("%d\n", v.size ());
  for (int i = 0; i < v.size (); i++)
    printf ("%d ", v [i]);
  puts ("");
  return 0;
}
