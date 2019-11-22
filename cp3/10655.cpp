#include <bits/stdc++.h>

void input ();
void solve ();

double p, q, n;


void input () {
	while (scanf ("%lF%lF", &p, &q) && p != 0 || q != 0) {
		scanf ("%lF", &n);
		solve ();
	}
}

void solve () {
	double delta = (p * p) * (-4) * q;
	double x1 = ((-p) + sqrt (delta)) / (-2);
	double x2 = ((-p) - sqrt (delta)) / (-2);
	printf ("delta: %lF, x1: %lF, x2: %lF\n", delta, x1, x2);
}

int main () {
	input ();
	solve ();
	return 0;
}
