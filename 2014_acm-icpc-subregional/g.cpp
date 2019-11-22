#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::set <int> si;

const int MAXN = 3e2 + 1;

int n, m;
int arr [MAXN][MAXN];
pi piar [MAXN][MAXN];
int column [MAXN], line [MAXN];
int inv;

int possible () {
	si l;
	for (int i = 0; i < n; i++) {
		l.clear ();
		for (int j = 0; j < m; j++)
			l.insert (piar [i][j].second);
		if (l.size () != m)
			return false;
	}
	for (int i = 0; i < m; i++) {
		l.clear ();
		for (int j = 0; j < n; j++)
			l.insert (piar [j][i].first);
		if (l.size () != n)
			return false;
	}
	return true;
}

void input () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m && scanf ("%d", arr [i] + j); j++) {
			arr [i][j]--;
			piar [i][j] = std::make_pair (arr [i][j] / m, arr [i][j] % m);
		}
	solve ();
}

void solve () {
	/*
	for (int i = 0; i < n; i++) {
		printf ("| ");
		for (int j = 0; j < m; j++)
			printf ("(%d){%d, %d} | ", arr [i][j], piar [i][j].first, piar [i][j].second);
		puts ("");
	}
	*/

	if (possible ()) {
		for (int i = 0; i < n; i++)
			line [i] = piar [i][0].first;
		for (int i = 0; i < m; i++)
			column [i] = piar [0][i].second;

		for (int i = 0; i < n; i++) {
			if (line [i] != i)
				for (int j = 0; j < n; j++)
					if (line [j] == i) {
						std::swap (line [i], line [j]);
						inv++;
					}
		}
		for (int i = 0; i < m; i++) {
			if (column [i] != i)
				for (int j = 0; j < m; j++)
					if (column [j] == i) {
						std::swap (column [i], column [j]);
						inv++;
					}
		}

		printf ("%d\n", inv);
	}
	else
		puts ("*");
}

int main () {
	input ();
	return 0;
}
