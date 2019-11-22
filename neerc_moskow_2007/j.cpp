#include <bits/stdc++.h>

#define y1 asodfaopsjfaoisd

void input ();
void solve ();

int x1, y1, x2, y2;

void input () {
	scanf ("%*s");
	scanf ("%*s");
	std::string in;

	std::cin >> in;
	x1 = atoi (in.substr (0, in.size () - 2).c_str ());
	scanf ("%*s");
	std::cin >> in;
	y1 = atoi (in.substr (0, in.size () - 2).c_str ());
	scanf ("%*s");

	std::cin >> in;
	x2 = atoi (in.substr (0, in.size () - 2).c_str ());
	scanf ("%*s");
	std::cin >> in;
	y2 = atoi (in.substr (0, in.size () - 2).c_str ());
	scanf ("%*s");

	solve ();
}

void solve () {
	int ans = 0;
	while (x1 != x2 || y1 != y2) {
		printf ("{%d, %d}, {%d, %d}\n", x1, y1, x2, y2);
		if (x1 % 2) {
			if (y1 % 2) {
				x1++;
				ans++;
			}
			else {
				y1++;
				ans++;
			}
		}
		else {
			if (y1 % 2) {
				y1++;
				ans++;
			}
			else {
				x1++;
				ans++;
			}
		}
	}
	printf ("%d\n", ans * 200);
}

int main () {
	input ();
	return 0;
}
