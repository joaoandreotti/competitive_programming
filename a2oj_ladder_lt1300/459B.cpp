#include <bits/stdc++.h>

int main () {
  long long n;
  scanf ("%lld", &n);
  long long arr [n];
  for (int i = 0; i < n; i++)
    scanf ("%lld", arr + i);
  std::sort (arr, arr + n);
  long long lowest = 1;
  for (int i = 1; i < n; i++)
    if (arr[i - 1] == arr [i])
      lowest++;
    else
      break;
  long long highest = 1;
  for (int i = n - 2; i >= 0; i--)
    if (arr[i + 1] == arr [i])
      highest++;
    else
      break;

   if (arr[n-1] - arr[0])
     printf ("%lld %lld\n", arr[n-1] - arr[0], ((long long)pow (lowest + 1, 2) - lowest + 1)/2);
   else
     printf ("%lld %lld\n", arr[n-1] - arr[0], ((long long)pow (lowest, 2) - lowest)/2);

  return 0;
}
