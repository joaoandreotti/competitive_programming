#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 1e2 + 10, INF = 0x3f3f3f3f;

int n, m, t, cs;
int s, d;
vvi g;
int arr [MAXN][MAXN], vis [MAXN];

int dfs (int x) {
	vis [x] = 1;

	int ans = 0;
	for (int v : g [x])
		if (!vis [v]) {
			printf ("{%d, %d}\n", x, v);
			ans += dfs (v) + arr [x][v];
		}

	return ans;
}

void input () {
	scanf ("%d", &t);
	for (cs  = 1; cs <= t; cs++) {
		scanf ("%d%d", &n, &m);
		g.clear ();
		g.resize (n);
		memset (arr, 0x3f, sizeof arr);
		memset (vis, 0, sizeof vis);
		for (int i = 0; i < n; i++)
			arr [i][i] = 0;
		for (int i = 0; i < m; i++) {
			int a, b; scanf ("%d%d", &a, &b);
			g [a].push_back (b);
			g [b].push_back (a);
			arr [a][b] = 1;
			arr [b][a] = 1;
		}
		scanf ("%d%d", &s, &d);
		solve ();
	}
}


// we need to find the largest distance between a node S -> U
// that U can reach D so U -> D
void solve () {
	// all pairs shortest path
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr [i][j] = std::min (arr [i][j], arr [i][k] + arr [k][j]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (arr [s][i] != INF && arr [i][d] != INF) {
			//printf ("{%d, %d} | {%d, %d}\n", s, i, i, d);
			ans = std::max (ans, arr [s][i] + arr [i][d]);
		}

	printf ("Case %d: %d\n", cs, ans);

}

int main () {
	input ();
	return 0;
}
