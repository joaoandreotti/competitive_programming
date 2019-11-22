#include <bits/stdc++.h>

void input ();
void solve ();

typedef long double ld;
typedef long long ll;

const ld EPS = 1e-9;

ll a, b, c;

void input () {
	scanf ("%lld%lld%lld", &a, &b, &c);
	solve ();
}

void solve () {
	ld delta = (b * b) - (4 * a * c);
	//printf ("%Lf\n", delta);
	if (a == 0)
		if (b != 0)
			printf ("1\n%Lf\n", (ld)(-c) / (ld)b);
		else
			if (!c)
				puts ("-1");
			else
				puts ("0");
	else if (delta < 0)
		puts ("0");
	else {
		ld x1 = (-b + sqrtl (delta)) / (2 * (ld)a);
		ld x2 = (-b - sqrtl (delta)) / (2 * (ld)a);
		if (x1 > x2)
			std::swap (x1, x2);
		if (delta)
			printf ("2\n%Lf\n%Lf\n", x1, x2);
		else
			printf ("1\n%Lf\n", x1);
	}
}

int main () {
	input ();
	return 0;
}
