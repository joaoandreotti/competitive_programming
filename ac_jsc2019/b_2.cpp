#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::vector <ll> vl;

const ll MOD = ((ll)1e9) + 7;
ll n, k;
vl arr, aux, fac;

void input () {
	scanf ("%lld%lld", &n, &k);
	for (ll i = 0, a; i < n; i++) {
		scanf ("%lld", &a);
		arr.push_back (a);
	}
	//for (int j = 0; j < k; j++)
	for (int i = 0; i < n; i++)
		arr.push_back (arr [i]);
	solve ();
}

void solve () {
	/*
	   for (int i = 0; i < arr.size (); i++)
	   printf ("%d ", arr [i]);
	   puts ("");
	   */
	for (int i = 0; i < arr.size (); i++) {
		ll c = 0;
		for (int j = i + 1; j < arr.size (); j++) {
			if (arr [i] > arr [j])
				c++;
		}
		aux.push_back (c);
	}
	for (int i = 0; i < n; i++)
		fac.push_back (aux [i] - aux [i + n]);
	aux.clear ();
	for (int i = 0; i < n; i++) {
		ll c = 0;
		for (int j = 0; j < i; j++)
			if (arr [i] > arr [j])
				c++;
		aux.push_back (c);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += ((fac [i] * (k + 1)) - aux [i]) % MOD;
	//printf ("{%lld, %lld}\n", fac [i], (fac [i] * (k + 1)) - aux [i]);
	printf ("%lld\n", ans % MOD);
}

int main () {
	input ();
	return 0;
}
