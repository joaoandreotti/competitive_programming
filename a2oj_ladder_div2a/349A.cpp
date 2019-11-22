#include <bits/stdc++.h>

int n, arr [(int)1e5 + 1], bills [2];

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (arr [i] == 50) {
      if (bills [0]) {
        bills [0]--;
        bills [1]++;
      }
      else
        flag = 1;
    }
    else if (arr [i] == 100) {
      if (bills [0] >= 1 && bills [1] >= 1) {
        bills [0]--;
        bills [1]--;
      }
      else if (bills [0] >= 3)
        bills [0] -= 3;
      else
        flag = 1;
    }
    else
      bills [0]++;
  }

  if (flag)
    puts ("NO");
  else
    puts ("YES");

  return 0;
}
