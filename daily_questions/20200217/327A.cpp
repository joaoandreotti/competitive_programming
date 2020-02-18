#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e2 + 1;

int n;
int arr [MAXN];
int cont [MAXN];
std::pair <int, int> range [MAXN];

void input () {
  scanf  ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  solve ();
}

void solve () {
  /* O (n ** 3)
  */
  int best = 0;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      int count = 0;
      for (int k = 0; k < n; k++)
        if (k < i || k > j) {
          if (arr [k])
            count++;
        }
        else
          if (!arr [k])
            count++;

      best = std::max (count, best);
    }

  printf ("%d\n", best);

  /*
  for (int i = 0; i < n; i++)
    if (arr [i])
      cont [i] = -1;
    else
      cont [i] = 1;


  int best = 0, sum = 0;
  int b = 0, e = 0;
  for (int i = 0; i < n; i++) {
    if (sum + cont [i] > cont [i])
      sum += cont [i];
    else {
      sum = cont [i];
      b = i;
    }

    if (sum > best) {
      e = i;
      best = sum;
    }
  }

  //printf ("{%d, %d}, best: %d\n", b, e, best);
  if (!best) // all 1
    printf ("%d\n", n - 1);
  else if (best == n) // all 0
    printf ("%d\n", best);
  else {
    int count = 0;
    for (int k = 0; k < n; k++)
      if (k < b || k > e) {
        if (arr [k])
          count++;
      }
      else
        if (!arr [k])
          count++;

    printf ("%d\n", count);
  }
  */

}

int main () {
  input ();
  return 0;
}
