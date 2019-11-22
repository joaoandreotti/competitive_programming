#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::tuple <ll, ll, ll> tl3;
typedef std::map <tl3, ll> mtl;

ll n;
ll a, b, c;
mtl dp, dc;

void input () {
  scanf ("%lld", &n);
  for (ll i = 0; i < n; i++) {
    scanf ("%lld%lld%lld", &a, &b, &c);
    solve ();
  }
}

void solve () {
  ll ans = 0;

  ll ia = a;

  a += c;

  puts ("----");
  while (a >= ia && a > b) {
    printf ("{%d, %d}\n", a, b);
    ans++;
    a--;
    b++;
  }

  printf ("%lld\n", ans);
}

int main () {
  input ();
  return 0;
}
