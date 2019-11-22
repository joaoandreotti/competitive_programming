#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e3, INF = 0x3f3f3f3f;

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;

int n, m;
vvpi g;
int arr [MAXN][MAXN], p [MAXN][MAXN];

void fw () {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				printf ("{%d, %d} => {%d, %d} {%d, %d}\n", i, j, i, k, k, j);
				if (arr [i][j] > arr [i][k] + arr [k][j] ) {
					printf ("{%d, %d} => {%d, %d} = %d\n", i, j, k, j, p [k][j]);
					arr [i][j] = std::min (arr [i][j], arr [i][k] + arr [k][j]);
					p [i][j] = p [k][j];
				}
			}
}

void path (int i, int j) {
	if (i != j)
		path (i, p [i][j]);
	printf ("%d ", j);
}

void input () {
	scanf ("%d%d", &n, &m);
	g.resize (n);
	memset (arr, 0x3f, sizeof arr);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			p [i][j] = i;
		arr [i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		g [a].push_back ({b, c});
		arr [a][b] = c;
	}
	solve ();
}

void solve () {
	fw ();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf ("%d ", arr [i][j]);
		puts ("");
	}
	puts ("shortest path");
	path (3, 4);
	puts ("");
}

int main () {
	input ();
	return 0;
}
