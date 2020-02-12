#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 5e5 + 1;

int n, k;
int arr [MAXN];

void input () {
  scanf ("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  solve ();
}

void solve () {
  int crr = 0;
  int ans = 0;
  int min = INT_MAX;

  for (int i = 0; i < k; i++)
    crr += arr [i];

  min = crr;

  for (int i = k; i < n; i++) {
    //printf ("crr: %d, min %d\n", crr, min);
    crr = (crr + arr [i]) - arr [i - k];

    if (crr < min) {
      min = crr;
      ans = (i - k) + 1;
    }
  }
  //printf ("crr: %d, min %d\n", crr, min);

  printf ("%d\n", ans + 1);
}

int main () {
  input ();
  return 0;
}
