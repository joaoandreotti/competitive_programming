#include <bits/stdc++.h>

int lights[5][5];

int main () {
  int a;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      scanf ("%d", &a);
      if (a != 0 && a % 2 == 1) {
        lights[i][j] = 1 - lights[i][j];

        lights[i + 1][j] = 1 - lights[i + 1][j];
        lights[i - 1][j] = 1 - lights[i - 1][j];
        lights[i][j + 1] = 1 - lights[i][j + 1];
        lights[i][j - 1] = 1 - lights[i][j - 1];

        /*
        lights[i + 1][j + 1] = 1 - lights[i + 1][j + 1];
        lights[i + 1][j - 1] = 1 - lights[i + 1][j - 1];
        lights[i - 1][j + 1] = 1 - lights[i - 1][j + 1];
        lights[i - 1][j - 1] = 1 - lights[i - 1][j - 1];
        */
      }
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++)
      printf ("%d", 1 - lights[i][j]);
    puts("");
  }
  return 0;
}
