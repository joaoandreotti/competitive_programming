#include <bits/stdc++.h>

#define y1 drysagbdIAUDFJIOKPKASJAKL

void input ();
void solve ();

const int inf = 0x3f3f3f3f;

typedef struct square {
	int x1, y1, x2, y2;
	square (int a, int b, int c, int d) : x1 (a), y1 (b), x2 (c), y2 (d) {}
} square;
typedef std::vector <square> vs;

int n, lx = -inf, rx = inf, by = -inf, ty = inf;
vs arr;

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d; scanf ("%d%d%d%d", &a, &b, &c, &d);
		arr.push_back ({a, b, c, d});
	}
	solve ();
}

void solve () {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		lx = std::max (lx, arr [i].x1);
		rx = std::min (rx, arr [i].x2);
		by = std::max (by, arr [i].y1);
		ty = std::min (ty, arr [i].y2);
	}

	//printf ("%d %d %d %d\n", lx, rx, by, ty);

	if (lx < rx && by < ty)
		sum = std::abs (lx - rx) * std::abs (by - ty);

	printf ("%d\n", sum);
}

int main () {
	input ();
	return 0;
}
