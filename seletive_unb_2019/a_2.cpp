#include <bits/stdc++.h>

void input ();
void solve ();

typedef struct point {
	int x, flag;
} point;

typedef std::vector <point> vp;

const int MAXN = 2e4 + 2;

int n, q, v;
vp arr;
int rd [MAXN];

int cmp (point a, point b) {
	if (a.x == b.x)
		return a.flag < b.flag;
	return a.x < b.x;
}

void input () {
	scanf ("%d%d%d", &n, &q, &v);
	for (int i = 0; i < q; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		if (c > v) {
			arr.push_back ({a, 0});
			arr.push_back ({b, 1});
			rd [a]++;
			rd [b + 1]--;
		}
	}
	solve ();
}

void solve () {
	std::sort (arr.begin (), arr.end (), cmp);
	int max = 0, cnt = 0;
	for (int i = 0; i < arr.size (); i++) {
		if (!arr [i].flag)
			cnt++;
		else
			cnt--;
		max = std::max (cnt, max);
	}
	//printf ("%d\n", max);
	if (max == 0) {
		puts ("-1");
		return;
	}
	int count = 0, crr = 0, best = 0;
	for (int i = 1; i <= n; i++) {
		count += rd [i];
		if (count == max)
			crr++;
		else
			crr = 0;
		best = std::max (crr, best);
	}
	printf ("%d\n", best);
}

int main () {
	input ();
	return 0;
}
