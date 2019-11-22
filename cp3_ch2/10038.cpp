#include <bits/stdc++.h>

int arr [(int)3e3 + 10], ans [(int)3e3 + 10];

int main () {
  int n;
  while (scanf ("%d", &n) != EOF) {
    int flag = 0;
    long long max = 0;
    memset (ans, 0, sizeof (ans));
    for (int i = 0; i < n; i++)
      scanf ("%d", arr + i);

    for (int i = 0; i < n - 1; i++) {
      ans [abs (arr [i] - arr [i + 1])] = 1;
    }

    for (int i = 1; i < n; i++) {
      //printf ("ans [%d]: %d\n", ans [i]);
      if (!ans [i])
        flag = 1;
    }


    if (flag)
      puts ("Not jolly");
    else
      puts ("Jolly");
  }

  return 0;
}
