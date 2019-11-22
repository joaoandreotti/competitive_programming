#include <bits/stdc++.h>

const int MAXN = 1e5 + 1;

int n, m; 
int arr1 [MAXN], arr2 [MAXN];

long long check (long long a) {
  long long sum = 0;
  for (int i = 0; i < n; i++)
    if (arr1 [i] < a)
      sum += a - arr1 [i];

  for (int i = 0; i < m; i++)
    if (arr2 [i] > a)
      sum += arr2 [i] - a;

  //printf ("sum: %lld, a: %lld\n", sum, a);
  return sum;
}

int main () {
  scanf ("%d%d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr1 + i);
    

  for (int i = 0; i < m; i++)
    scanf ("%d", arr2 + i);

  // bs the answer
  long long h = 0x3f3f3f3f3f3f3f3f, l = 0;
  long long mid = (h + l) / 2;
  long long ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = 0; i < 100; i++) {
    //printf ("h: %lld, l: %lld, mid: %lld\n", h, l, mid);
    long long a = check (mid), b = check (mid + 1);
    if (a < b) {
      h = mid;
      ans = a;
    }
    else {
      l = mid;
      ans = std::min (ans, b);
    }

    mid = (h + l) / 2;
  }

  printf ("%lld\n", ans);

    
  return 0;
}
