#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 1e2 + 10;

int t, n, off, cs;
vvi g;
int visited [MAXN];
char ans [MAXN][MAXN];

void dfs (int x) {
	visited [x] = 1;
	for (int v : g [x]) {
		if (off != v && !visited [v])
			dfs (v);
	}
}

void input () {
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d", &n);
		g.clear ();
		g.resize (n);
		int a;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf ("%d", &a);
				if (a)
					g [i].push_back (j);
			}
		solve ();
	}
}

void solve () {
	memset (ans, 1, sizeof ans);
	memset (visited, 0, sizeof visited);
	off = -1;
	dfs (0);
	for (int i = 0; i < n; i++)
		if (!visited [i])
			ans [0][i] = 0;

	for (int i = 1; i < n; i++) {
		memset (visited, 0, sizeof visited);
		off = i;
		dfs (0);
		for (int j = 0; j < n; j++)
			if (!ans [0][j] || visited [j])
				ans [i][j] = 0;
	}

	printf ("Case %d:\n", ++cs);
	for (int i = 0; i < n; i++) {
		printf ("+");
		for (int i = 0; i < (2 * n) - 1; i++)
			printf ("-");
		printf ("+\n|");
		for (int j = 0; j < n; j++)
			if (ans [i][j])
				printf ("Y|");
			else
				printf ("N|");
		puts ("");
	}
	printf ("+");
	for (int i = 0; i < (2 * n) - 1; i++)
		printf ("-");
	printf ("+\n");
}

int main () {
	input ();
	return 0;
}
