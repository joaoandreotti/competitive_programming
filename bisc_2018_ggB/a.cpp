#include <bits/stdc++.h>

void input ();
void solve ();

typedef long double ld;

typedef struct vector {
	ld x = 0, y = 0;
	vector () {}
	vector (ld x, ld y) : x (x), y (y) {}
	bool operator< (vector a) {
		if (x == a.x)
			return y < a.y;
		return x < a.x;
	}

} vector;

vector v1, v2, arr [4];

void input () {
	ld a, b, c, d;
	// vector 1
	scanf ("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);
	v1.x = c - a;
	v1.y = d - b;

	// vector 2
	scanf ("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);
	v2.x = c - a;
	v2.y = d - b;

	solve ();
}

void solve () {
	printf ("%.20Lf %.20Lf\n", hypotl (v1.x, v1.y), hypotl (v2.x, v2.y));
	printf ("%.20Lf %.20Lf\n", v1.x + v2.x, v1.y + v2.y);
	printf ("%.20Lf %.20Lf\n", (v1.x * v2.x) + (v1.y * v2.y), (v1.x * v2.y) - (v2.x * v1.y));

	ld ans = 0;
	arr [0] = v1;
	arr [1] = v2;
	arr [2] = {0, 0};
	arr [3] = v1;
	for (int i = 0; i < 3; i++) {
		ans += (ld)arr [i].x * (ld)arr [i + 1].y;
		ans -= (ld)arr [i].y * (ld)arr [i + 1].x;
	}
	printf ("%.20Lf\n", std::abs (ans / 2.0));
}

int main () {
	input ();
	return 0;
}
