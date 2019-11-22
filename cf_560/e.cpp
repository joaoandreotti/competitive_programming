#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;

const ll MOD = 998244353;
const int MAXN = 2e5 + 1;

ll n;
ll arr [MAXN], brr [MAXN];


void input () {
	scanf ("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf ("%lld", arr + i);
	for (int i = 0; i < n; i++)
		scanf ("%lld", brr + i);
	solve ();
}

void solve () {
	for (int i = 0; i < n; i++)
	       arr [i] = arr [i] * (i + 1) * (n - i);

	std::sort (arr, arr + n);
	std::sort (brr, brr + n);
	std::reverse (brr, brr + n);

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += (arr [i] % MOD) * (brr [i] % MOD) % MOD;
	printf ("%lld\n", ans % MOD);
}

int main () {
	input ();
	return 0;
}
