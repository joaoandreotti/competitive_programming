#include <bits/stdc++.h>

int arr[(int)1e5]; // bitmap
int n;

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    arr [a] = i + 1;
  }

  int m;
  scanf ("%d", &m);
  long long vasya = 0, petya = 0;
  for (int i = 0; i < m; i++) {
    int q;
    scanf ("%d", &q);
    vasya += arr [q];
    petya += (n + 1) - arr [q];
  }

  printf ("%lld %lld\n", vasya, petya);
  return 0;
}
