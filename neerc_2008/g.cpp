#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

typedef long long ll;

typedef struct tv {
	int rh, rv, sh, sv, p;
} tv;

typedef std::vector <ll> vll;

int n;
int rh, rv, sh, sv;
tv arr [MAXN];
vll ans;

void input () {
	freopen ("giant.in", "r", stdin);
	freopen ("giant.out", "w", stdout);

	scanf ("%d%d%d%d", &rh, &rv, &sh, &sv);
	scanf ("%d", &n);

	for (int i = 0; i < n; i++)
		scanf ("%d%d%d%d%d", &arr [i].rh, &arr [i].rv, &arr [i].sh, &arr [i].sv, &arr [i].p);

	solve ();
}

void solve () {
	for (int i = 0; i < n; i++) {
		ll partial = 1;
		int tx = 0, ty = 0;

		if (rh % arr [i].rh == 0)
			tx = rh / arr [i].rh;
		else
			tx = (rh / arr [i].rh) + 1;
		if (sh % arr [i].sh == 0)
			tx = std::max (tx, sh / arr [i].sh);
		else
			tx = std::max (tx, (sh / arr [i].sh) + 1);

		if (rv % arr [i].rv == 0)
			ty = rv / arr [i].rv;
		else
			ty = (rv / arr [i].rv) + 1;
		if (sv % arr [i].sv == 0)
			ty = std::max (ty, sv / arr [i].sv);
		else
			ty = std::max (ty, (sv / arr [i].sv) + 1);

		partial = (ll)tx * (ll)ty * (ll)arr [i].p;

		ans.push_back (partial);
	}

	for (int i = 0; i < n; i++) {
		ll partial = 1;
		int tx, ty;

		if (rh % arr [i].rv == 0)
			tx = rh / arr [i].rv;
		else
			tx = (rh / arr [i].rv) + 1;
		if (sh % arr [i].sv == 0)
			tx = std::max (tx, sh / arr [i].sv);
		else
			tx = std::max (tx, (sh / arr [i].sv) + 1);

		if (rv % arr [i].rh == 0)
			ty = rv / arr [i].rh;
		else
			ty = (rv / arr [i].rh) + 1;
		if (sv % arr [i].sh == 0)
			ty = std::max (ty, sv / arr [i].sh);
		else
			ty = std::max (ty, (sv / arr [i].sh) + 1);

		partial = (ll)tx * (ll)ty * (ll)arr [i].p;

		ans.push_back (partial);
	}

	std::sort (ans.begin (), ans.end ());

	printf ("%lld\n", ans [0]);
}

int main () {
	input ();
	return 0;
}
