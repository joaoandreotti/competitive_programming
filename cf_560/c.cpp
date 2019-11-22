#include <bits/stdc++.h>

void input ();
void solve ();

int n;
std::string str;

void input () {
	scanf ("%d", &n);
	std::cin >> str;
	solve ();
}

void solve () {
	std::string a;
	a = str [0];
	for (int i = 1, j; i < n; i++) {
		if (a.size () % 2) {
			if (str [i] != a [a.size () - 1])
				a += str [i];
		}
		else
			a += str [i];
	}

	if (a.size () % 2)
		a.pop_back ();

	printf ("%d\n%s\n", str.size () - a.size (), a.c_str ());
}

int main () {
	input ();
	return 0;
}
