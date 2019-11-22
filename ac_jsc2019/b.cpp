#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::vector <ll> vl;

const ll MOD = (ll)1e9 + 7;
ll n, k;
vl arr, fac;
vl lt, ltb, lta;

ll sum (int i) {
	ll x = (((lta [i] + ((lt [i] * k) - ltb [i])) % MOD) * (k % MOD)) % MOD;
	return x * 500000004;
}

void input () {
	scanf ("%lld%lld", &n, &k);
	for (ll i = 0, a; i < n; i++) {
		scanf ("%lld", &a);
		arr.push_back (a);
	}
	solve ();
}

void solve () {
	for (int i = 0; i < n; i++) {
		ll c = 0;
		for (int j = (i + 1) % n; j != i; j = (j + 1) % n)
			if (arr [i] > arr [j])
				c++;
		lt.push_back (c);
	}

	for (int i = 0; i < n; i++) {
		ll c = 0;
		for (int j = 0; j < i; j++)
			if (arr [i] > arr [j])
				c++;
		ltb.push_back (c);
	}

	for (int i = 0; i < n; i++) {
		ll c = 0;
		for (int j = i + 1; j < n; j++)
			if (arr [i] > arr [j])
				c++;
		lta.push_back (c);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		//printf ("{%lld, %lld}\n", lta [i], (lt [i] * k) - ltb [i]);
		ans += (sum (i)) % MOD;
	}
	printf ("%lld\n", (ans) % MOD);
}

int main () {
	input ();
	return 0;
}
