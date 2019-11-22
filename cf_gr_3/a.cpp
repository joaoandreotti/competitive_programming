#include <bits/stdc++.h>

void solve ();
void input ();

long long a, b, c;

void input () {
	scanf ("%lld%lld%lld", &a, &b, &c);
	solve ();
}

void solve () {
	long long ans = (2*c) + (std::min (a, b) * 2);

	if (std::min (a, b) < std::max (a, b))
		ans++;
	printf ("%lld\n", ans);
}

int main () {
	input ();
	return 0;
}
