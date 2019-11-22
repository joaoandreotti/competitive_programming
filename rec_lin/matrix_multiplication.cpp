#include <bits/stdc++.h>

const int MAXN = 1e3;

// m == p
int n, m, p, q;
int m1 [MAXN][MAXN], m2 [MAXN][MAXN], ans [MAXN][MAXN];

void input ();
void solve ();

int sum (int i, int j) {
	int s1 = 0;
	for (int k = 0; k < m; k++) {
		s1 += m1 [i][k] * m2 [k][j];
	}
	return s1;
}

void f () {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < q; j++) {
			ans [i][j] = sum (i, j);
		}
	}
}

void input () {
	scanf ("%d%d%d%d", &n, &m, &p, &q);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", m1 [i] + j);
	for (int i = 0; i < p; i++)
		for (int j = 0; j < q; j++)
			scanf ("%d", m2 [i] + j);
}

void solve () {
	f ();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < q; j++)
			printf ("%d ", ans [i][j]);
		puts ("");
	}
}

int main () {
	input ();
	solve ();
	return 0;
}
