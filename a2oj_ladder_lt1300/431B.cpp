#include <bits/stdc++.h>

int main () {
  int n = 5;
  int matrix[n][n], queue [n];
  for (int i = 0; i < n; i++) {
    queue [i] = i;
    for (int j = 0; j < n; j++)
      scanf ("%d", &matrix [i][j]);
  }

  long long max = 0;
  do {
    long long perm = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j += 2)
        if (j + 1 < n) {
          perm += matrix [queue [j]][queue [j + 1]];
          perm += matrix [queue [j + 1]][queue [j]];
        }
    }
    max = std::max (max, perm);
  } while (std::next_permutation (queue, queue + 5));

  printf ("%lld\n", max);
    
  return 0;
}
