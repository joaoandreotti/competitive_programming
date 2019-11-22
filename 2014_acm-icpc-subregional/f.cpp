#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::set <ll> si;
typedef std::map <ll, ll> mi;
typedef std::set <si> ssi;
const int MAXN = 1e5 + 1;

ll n;
ll arr [MAXN];
mi map;
ssi trgl;

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n && scanf ("%lld", arr + i); i++)
		if (i)
			arr [i] += arr [i - 1];
	solve ();
}

void solve () {
	ll sum = arr [n - 1];
	for (int i = 0; i < n; i++)
		map [arr [i]] = 1;

	if (sum % 3)
		puts ("0");
	else {
		ll stp = sum / 3;
		for (ll i = 0; i < n; i++) {
			si a;
			a.insert (arr [i]);
			if (map [arr [i] + stp])
				a.insert (arr [i] + stp);
			if (map [arr [i] + stp + stp])
				a.insert (arr [i] + stp + stp);

			if (a.size () == 3)
				trgl.insert (a);
		}
		printf ("%d\n", (int)trgl.size ());
	}
}

int main () {
	input ();
	return 0;
}
