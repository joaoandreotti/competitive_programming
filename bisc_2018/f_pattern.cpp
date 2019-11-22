#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;

ll n;

void input () {
	scanf ("%lld", &n);
	solve ();
}

void solve () {

	ll count = 0;
	for (ll i = 0; i < (1LL << n); i++) {
		ll flag = 0;
		for (ll j = 0; j < n + 1; j++)
			if ((i >> j) & 1 && (i >> (j + 1) & 1))
				flag = 1;

		if (flag)
			continue;

		printf ("%3lld --- ", count);
		count++;
		
		for (ll j = n - 1; j >= 0; j--)
			if ((i >> j) & 1)
				printf ("1");
			else
				printf ("0");
		printf ("--- %lld\n", i);
	}
	//printf ("%lld\n", count);
}

int main () {
	input ();
	return 0;
}
