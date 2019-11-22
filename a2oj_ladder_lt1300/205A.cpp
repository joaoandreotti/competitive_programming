#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  int arr[n];
  long long min = INT_MAX, pos;
  for (int i = 0; i < n; i++) {
    scanf ("%lld", arr + i);
    if (min > arr[i]) {
      min = arr[i];
      pos = i + 1;
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (min == arr[i])
      count++;
    if (count >= 2) {
      puts ("Still Rozdil");
      return 0;
    }
  }

  printf ("%lld\n", pos);
  return 0;
}
