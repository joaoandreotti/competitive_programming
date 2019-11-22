#include <bits/stdc++.h>

void input ();
void solve ();

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef std::pair <ll, ll> pi;
typedef std::vector <pi> vpi;

int n;
vpi arr;


void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		ll a, b; scanf ("%lld%lld", &a, &b);
		if (a > b)
			std::swap (a, b);
		arr.push_back ({a, b});
	}
	solve ();
}

void solve () {
	std::sort (arr.begin (), arr.end ());
	ll ans = 0, last = -INF;
	for (int i = 0; i < n; i++) {
		ans += arr [i].second - arr [i].first;

		if (last - arr [i].second > 0)
			ans -= arr [i].second - arr [i].first;
		else if (last - arr [i].first > 0)
			ans -= last - arr [i].first;

		if (arr [i].second > last)
			last = arr [i].second;
	}

	printf ("%lld\n", ans);
}

int main () {
	input ();
	return 0;
}
