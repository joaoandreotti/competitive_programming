#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;

typedef struct point {
	ll x, flag;
} point;

typedef std::vector <point> vp;

bool cmp (point a, point b) {
	if (a.x == b.x)
		return a.flag < b.flag;
	return a.x < b.x;
}

int n;
vp arr;

void input () {
	scanf ("%d", &n);

	for (int i = 0; i < n; i++) {
		char k;
		ll a, b, c;scanf ("%lld%c%lld%c%lld", &a, &k, &b, &k, &c);
		ll d, e, f;scanf ("%lld%c%lld%c%lld", &d, &k, &e, &k, &f);
		arr.push_back ({(a * 3600) + (b * 60) + c, 0}); // in
	       	arr.push_back ({(d * 3600) + (e * 60) + f, 1}); // out
	}
	solve ();
}

void solve () {
	std::sort (arr.begin (), arr.end (), cmp);
	int chairs = 0;
	int max = 0;
	for (int i = 0; i < arr.size (); i++) {
		//printf ("{%lld, %lld}\n", arr [i].x, arr [i].flag);
		if (!arr [i].flag)
			chairs++;
		else
			chairs--;
		max = std::max (max, chairs);
	}
	printf ("%d\n", max);
}

int main () {
	input ();
	return 0;
}
