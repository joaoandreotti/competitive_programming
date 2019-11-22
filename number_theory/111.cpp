#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
const int MAXN = 1e4, MAXP = 1e8;

ll n;
std::vector <long long> isp (MAXN, true), p, spf (MAXN);
ll primes [MAXP];

ll g (ll x) {
	ll ans = 0;
	for (int k = 0; k <= x/2; k++) {
		if (x % 2) {
			if (primes [k] && !((x - k) % 2)) {
				printf ("%lld:\n", k)
				ans += g (x - k);
			}
		}
		else {
			if (primes [k] && primes [x - k]) {
				printf ("{%lld, %lld}\n", k, x - k);
				ans++;
			}
		}
	}
	return ans;
}

void sieve () {
	isp [0] = false;
	isp [1] = false;

	for (ll i = 2; i <= MAXN; i++) {
		if (isp [i]) {
			primes [i] = 1;
			p.push_back (i);
			spf [i] = i;
		}

		for (ll j = 0; (j < p.size ()) && (i * p [j] < MAXN) && (p [j] <= spf [i]); j++) {
			isp [i * p [j]] = false;
			spf [i * p [j]] = p [j];
		}
	}
}

void input () {
	scanf ("%lld", &n);
	solve ();
}

void solve () {
	sieve ();
	printf ("%lld\n", g (n));
}

int main () {
	input ();
	return 0;
}
