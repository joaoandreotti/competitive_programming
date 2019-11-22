#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;
typedef std::map <int, int> mi;

const int MAXN = 5e2 + 1, INF = 0x3f3f3f3f;

int n, m, l;
int vis [MAXN];
vi ids;
vvi dc, ac;
mi map;

int dfs (int x) {
	vis [x] = 1;
	int ans = INF;
	for (auto v : ac [x])
		ans = std::min (ids [v], ans);
	for (auto v : ac [x]) {
		if (!vis [v])
			ans = std::min (dfs (v), ans);
	}

	return ans;
}

void input () {
	scanf ("%d%d%d", &n, &m, &l);
	dc.resize (n);
	ac.resize (n);
	for (int i = 0, a; i < n && scanf ("%d", &a); i++) {
		ids.push_back (a);
		map [i] = i;
	}

	for (int i = 0, a, b; i < m && scanf ("%d%d", &a, &b); i++) {
		a--; b--;
		dc [a].push_back (b);
		ac [b].push_back (a);
	}

	/*
	puts ("INITIAL");
	for (int k = 0; k < n; k++) {
		printf ("%d(%d): ", k, ids [k]);
		for (int j = 0; j < dc [k].size (); j++)
			printf ("%d(%d) ", dc [k][j], ids [dc [k][j]]);
		puts ("");
	}
	puts ("ASC");
	for (int k = 0; k < n; k++) {
		printf ("%d(%d): ", k, ids [k]);
		for (int j = 0; j < ac [k].size (); j++)
			printf ("%d(%d) ", ac [k][j], ids [ac [k][j]]);
		puts ("");
	}
	*/

	solve ();
}

void solve () {
	for (int i = 0, a, b; i < l; i++) {
		char op; scanf ("\n%c", &op);
		if (op == 'P') {
			scanf ("%d", &a);
			a--;
			memset (vis, 0, sizeof vis);
			int ans = dfs (map [a]);
			if (ans == INF)
				puts ("*");
			else
				printf ("%d\n", ans);
		}
		else {
			scanf ("%d%d", &a, &b);
			a--; b--;
			int ax = map [a], bx = map [b];
			std::swap (ids [ax], ids [bx]);
			std::swap (map [a], map [b]);
			/*
			printf ("changed: {%d, %d}\n", a, b);
			for (auto x : map)
				printf ("{%d, %d}\n", x.first, x.second);
				*/
		}
	}
}

int main () {
	input ();
	return 0;
}
