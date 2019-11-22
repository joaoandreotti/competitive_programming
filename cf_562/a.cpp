#include <bits/stdc++.h>

void input ();
void solve ();


int n, a, x, b, y;

void input () {
	scanf ("%d%d%d%d%d", &n, &a, &x, &b, &y);
	a--; x--; b--; y--;
	solve ();
}

void solve () {
	int flag = 0;
	int d = a, v = b;

	while (d != x && v != y) {
		//printf ("{%d, %d}\n", d, v);
		d = (d + 1) % n;
		v = (v - 1) % n;
		if (v < 0)
			v = n - 1;

		if (d == v)
			flag = 1;
		//printf ("{%d, %d}\n", d, v);
	}
	if (flag)
		puts ("YES");
	else
		puts ("NO");
}

int main () {
	input ();
	return 0;
}
