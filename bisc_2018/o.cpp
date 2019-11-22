#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e3 + 1;

typedef long long ll;

int n;
ll arr [MAXN];

void input () {
	scanf ("%d", &n);
	solve ();
}

void solve () {
	for (ll i = 1; i <= n; i++)
		arr [i - 1] = i;

	ll lcm = (ll) arr [0];
	for (int i = 1; i < n; i++)
		lcm = (arr [i] * lcm) / std::__gcd (std::min (arr [i], lcm), std::max (arr [i], lcm));
	printf ("%lld\n", lcm);
}

int main () {
	input ();
	return 0;
}
