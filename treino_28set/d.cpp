#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

typedef long long ll;

ll n, ans;
ll arr [MAXN];


ll gcd (ll a, ll b) {
  return b == 0 ? a : gcd (b, a % b);
}

void input () {
  scanf ("%lld", &n);

  for (int i = 0; (i < n) && scanf ("%lld", arr + i); i++);

  solve ();
}

void solve () {
  ll max = *std::max_element (arr, arr + n);

  ll gn = max - arr [0];
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    gn = gcd (gn, max - arr [i]);
    sum += max - arr [i];
  }

  printf ("%lld %lld\n", sum / gn, gn);
}

int main () {
  input ();
  return 0;
}
