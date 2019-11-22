#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  int posx, posy, min = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    if (abs (arr[i % n] - arr[(i + 1) % n]) < min) {
      min = abs (arr[i % n] - arr[(i + 1) % n]);
      posx = (i) + 1;
      posy = ((i + 1) % n) + 1;
    }
  }
  printf ("\x1b[34m%d %d\n", posx, posy);
}
