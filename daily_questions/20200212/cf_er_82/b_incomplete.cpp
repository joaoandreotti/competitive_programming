#include <bits/stdc++.h>

void input ();
void solve ();

long long t, n;
long long g, b;

void input () {
  scanf ("%lld", &t);

  while (t--) {
    scanf ("%lld%lld%lld", &n, &g, &b);
    solve ();
  }
}

void solve () {
  // minimum number of g days
  long long half = n / 2 + n % 2;

  // number of leftover days (could be accomplished by gdays or bdays)
  long long left = n - half;

  long long minimum = ((half / g) * g) + (half % g);

  long long ans = ;

}

int main () {
  input ();
  return 0;
}
