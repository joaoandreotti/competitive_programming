#include <bits/stdc++.h>

int arr [100];

int main () {
  int n; scanf ("%d", &n);

  int max = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    scanf ("%d", arr + i);
    sum += arr [i];
    if (arr [i] > max)
      max = arr [i];
  }

  int my_sum = 0;
  for (int i = max; i <= (max * 2); i++) {
    my_sum = 0;

    for (int j = 0; j < n; j++) {
      my_sum += i - arr [j];
    }

    if (my_sum > sum) {
      printf ("%d\n", i);
      return 0;
    }
    else if (my_sum == sum) {
      printf ("%d\n", i + 1);
      return 0;
    }
  }


  return 0;
}
