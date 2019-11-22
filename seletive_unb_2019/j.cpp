#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;

ll v, a;

void input () {
	scanf ("%lld%lld", &v, &a);
	solve ();
}

void solve () {
	for (ll i = 1; (i * i) <= v; i++) {
		if (!(v % (i * i)) && a == ((2 * (i * i)) + (4 * i * (v / (i * i))))) {
			printf ("%lld %lld\n", i, (v / (i * i)));
			break;
		}
	}
}

int main () {
	input ();
	return 0;
}
