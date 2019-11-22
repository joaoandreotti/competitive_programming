#include <bits/stdc++.h>

void input ();

long long n, x, y;
long long ans, idx;

void input () {
	scanf ("%lld%lld%lld", &n, &x, &y);
	ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		long long a, b, c; scanf ("%lld%lld%lld", &a, &b, &c);
		long long cost = abs (x - a) + abs (y - b);
		cost *= 2;
		cost += c;
		if (cost < ans) {
			ans = cost;
			idx = i;
		}
	}
	printf ("%lld %lld\n", ans, idx);
}

int main () {
	input ();
	return 0;
}
