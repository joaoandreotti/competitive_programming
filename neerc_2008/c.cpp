#include <bits/stdc++.h>

void input ();
void solve ();

typedef long double ld;
typedef long long ll;
typedef std::pair <int, int> pi;
typedef std::vector <ld> vld;
typedef std::map <pi, ld> mpl;

const int MAXN = 1e2;
const ld PI = acosl (-1);

vld mint;
ll d [MAXN], l [MAXN];
ll n, t;
mpl dp;


ld f (ld li, ld di) {
	return (2 * PI * li) / di;
}

ld bt (int pos, ll t) {
	if (dp.find ({pos, t}) != dp.end ())
		return dp [{pos, t}];

	if (pos >= n || !t)
		return (ld)0;

	ll bwd = t % d [pos];
	ll fwd = d [pos] - bwd;

	ld db = bwd * mint [pos];
	ld df = fwd * mint [pos];

	return dp [{pos, t}] = std::min (bt (pos + 1, t / d [pos]) + db, bt (pos + 1, (t / d [pos]) + 1) + df);
}

void input () {
	scanf ("%lld", &n);
	d [0] = 60;
	for (int i = 1; i < n; i++)
		scanf ("%lld", d + i);
	for (int i = 0; i < n; i++)
		scanf ("%lld", l + i);

	ll a, b;
	scanf ("%lld%lld", &a, &b);
	t = std::abs (b - a);
	solve ();
}

void solve () {
	mint.push_back (f (l [0], d [0]));
	for (int i = 1; i < n; i++)
		mint.push_back (std::min (f (l [i], d [i]), d [i - 1] * mint [i - 1]));
	printf ("%.9Lf\n", bt (0, t));
}

int main () {
	freopen ("clock.in", "r", stdin);
	freopen ("clock.out", "w", stdout);
	input ();
	return 0;
}
