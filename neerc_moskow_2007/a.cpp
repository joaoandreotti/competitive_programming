#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;

ll x;

ll gaus (ll n) {
	return (((n + 1) * n) / 2);
}

ll rgaus (ll n) {
	if (n <= 0)
		return 0;

	return gaus ((n / 2) + (n % 2)) + rgaus ((n / 2) - 1);
}

void input () {
	scanf ("%lld", &x);
	x--;
	solve ();
}

void solve () {
	printf ("%lld\n", rgaus ((x / 2) - 1) + gaus ((x / 2) + (x % 2)));
}

int main () {
	input ();
	return 0;
}
