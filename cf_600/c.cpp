#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

int n, m;
long long arr [MAXN];
long long brr [MAXN];
long long crr [MAXN];

void input () {
  scanf ("%d%d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf ("%lld", arr + i);

  solve ();
}

void solve () {
  std::sort (arr, arr + n);

  long long sum = 0, day = 1, count = 0, part = 0;
  int flag = 0;

  for (int i = 0; i < n; i++) {
    if (i % m)
      if (i)
        brr [i] = arr [i] + brr [i - m];
      else
        brr [i] = arr [i];
    else
      if (i)
        crr [i] = arr [i] + crr [i - m];
      else
        crr [i] = arr [i];
  }

  for (int i = 0; i < m ; i++) {
    sum += arr [i];
    printf ("%lld ", sum);
  }

  for (int k = m; k < n; k++) {

    if (k % m) {
      sum += brr [k];
    }
    else {
      sum += crr [k];
    }
    printf ("%lld ", sum);
  }
  puts ("");
}

int main () {
  input ();
  return 0;
}
