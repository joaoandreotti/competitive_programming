#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::vector <ll> vi;
typedef std::vector <vi> vvi;

const int MAXN = 1e5 + 1;

ll n;
ll cost [3][MAXN];
ll arr [3] = {0, 1, 2};
ll ans [3];
ll vis [MAXN];
ll f [MAXN];
vvi g;

ll dfs (ll x, ll i) {
  vis [x] = 1;
  ll min = LLONG_MAX, crr = 0;
  for (ll v : g [x])
    if (!vis [v]) {
      crr = dfs (v, (i + 1) % 3);
      if (crr < min)
        min = crr;
    }
  
  if (min != LLONG_MAX)
    return min + cost [arr [i]][x];
  return cost [arr [i]][x];
}

void dfs_ans (ll x, ll i) {
  vis [x] = 1;
  f [x] = ans [i];
  for (ll v : g [x])
    if (!vis [v])
      dfs_ans (v, (i + 1) % 3);
}

void input () {
  scanf ("%lld", &n);

  for (ll k = 0; k < 3; k++)
    for (ll i = 0; i < n; i++)
      scanf ("%lld", cost [k] + i);

  g.resize (n);
  for (ll i = 0, a, b; i < (n - 1) && scanf ("%lld%lld", &a, &b); i++) {
    a--; b--;
    g [a].push_back (b);
    g [b].push_back (a);
  }

  solve ();
}

void solve () {
  int flag = 0;
  for (int i = 0; i < n; i++)
    if (g [i].size () > 2)
      flag = 1;

  if (flag)
    puts ("-1");
  else {
    ll min = LLONG_MAX;
    do {
      memset (vis, 0, sizeof vis);
      ll aux = dfs (0, 0);
      if (aux < min) {
        min = aux;
        for (ll i = 0; i < 3; i++)
          ans [i] = arr [i] + 1;
      }

    } while (std::next_permutation (arr, arr + 3));

    memset (vis, 0, sizeof vis);
    dfs_ans (0, 0);
    printf ("%lld\n", min);
    for (int i = 0; i < n; i++) {
      if (i + 1 < n)
        printf ("%lld ", f [i]);
      else
        printf ("%lld\n", f [i]);
    }
  }
}

int main () {
  input ();
  return 0;
}
