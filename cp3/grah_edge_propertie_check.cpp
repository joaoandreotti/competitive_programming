#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 2e2 + 1, explored = 2;

int n, m;
vvi g;
int visited [MAXN];

void dfs (int x, int f) {
	visited [x] = explored;
	for (int v : g [x]) {
		if (!visited [v]) {
			printf ("Tree-edge: {%d, %d}\n", x, v);
			dfs (v, x);
		}
		else if (visited [v] == explored && v != x)
			printf ("Back-edge: {%d, %d}\n", x, v);
		else
			printf ("Forward/cross: {%d, %d}\n", x, v);
	}
	visited [x] = 1;
}

void input () {
	scanf ("%d%d", &n, &m);
	g.clear ();
	g.resize (n);
	memset (visited, 0, sizeof visited);
	for (int i = 0; i < m; i++) {
		int a, b; scanf ("%d%d", &a, &b);
		g [a].push_back (b);
		g [b].push_back (a);
	}
	solve ();
}

void solve () {
	dfs (0, 0);
}

int main () {
	input ();
	return 0;
}
