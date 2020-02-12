#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e6 + 1;

int a, b, c;
int arr [MAXN];

long long d (int x) {
  long long count = 0;
  for (int i = 1; (i * i) <= x; i++)
    if (x % i == 0)
      if (x != (i*i))
        count += 2;
      else
        count += 1;

  return count;
}

void input () {
  scanf ("%d%d%d", &a, &b, &c);

  solve ();
}

void solve () {
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++)
        arr [i * j * k]++;

  long long ans = 0;
  for (int i = 1; i <= (a * b * c); i++)
    if (arr [i]) {
      //printf ("arr [%d]: %d\n", i, arr [i]);
      ans += (d (i) * arr [i]) % (1 << 30);
    }

  printf ("%lld\n", ans % (1 << 30));
}

int main () {
  input ();
  return 0;
}
