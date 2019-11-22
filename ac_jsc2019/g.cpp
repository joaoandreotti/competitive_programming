#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

int n, m;
int x, y;
char op;
vi arr;
vvi g;

void input () {
	scanf ("%d%d", &n, &m);
	for (int i = 0, a; i < n; i++) {
		scanf ("%d", &a);
		arr.push_back (a);
	}
	solve ();
}

void solve () {
	g.resize (n);
	for (int i = 0; i < m; i++) {
		scanf ("%c", &op);
		if (op == '?');
			// sol
		else {
			scanf ("%d%d", &x, &y);
		}
	}
}

int main () {
	return 0;
}
