#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::set <long long> si;

const int MAXN = 3e3 + 1;

int t, n;
long long arr [MAXN];
si d;

long long lcm (long long a, long long b) {
	return (a * b) / std::__gcd (a, b);
}

si div (long long a) {
	si ans;
	for (long long i = 2; (i * i) <= a; i++) {
		if (a % i == 0) {
			ans.insert (i);
			ans.insert (a / i);
		}
	}
	return ans;
}

void input () {
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d", &n);
		d.clear ();
		for (int j = 0; j < n; j++) {
			scanf ("%lld", arr + j);
			d.insert (arr [j]);
		}
		solve ();
	}
}

void solve () {
	std::sort (arr, arr + n);
	long long max = arr [0] * arr [n - 1];
	if (div (max) == d)
		printf ("%lld\n", max);
	else
		puts ("-1");
}

int main () {
	input ();
	return 0;
}
