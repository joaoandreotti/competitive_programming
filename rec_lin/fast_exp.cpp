#include <bits/stdc++.h>

typedef long long ll;

int n, m;
ll ans;

void input ();
void solve ();

ll f (ll b, ll e) {
	if (e == 0)
		return 1;

	ll ans = f (b, e / 2);
	ans *= ans;
	if (e % 2)
		ans *= b;

	return ans;
}

void input () {
	scanf ("%d%d", &n, &m);
}

void solve () {
	ans = f (n, m);
	printf ("%lld\n", ans);
}

int main () {
	input ();
	solve ();
	return 0;
}
