#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::set <int> si;

int n;
si set;

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf ("%d", &a);
		set.insert (a);
	}
	solve ();
}

void solve () {
	if (n % 2 == 0)
		for (auto i = set.rbegin (); i != set.rend (); i++)
			printf ("%d\n", *i);
	else
		for (auto i = set.begin (); i != set.end (); i++)
			printf ("%d\n", *i);
}

int main () {
	input ();
	return 0;
}
