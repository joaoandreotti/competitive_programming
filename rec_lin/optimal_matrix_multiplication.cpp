#include <bits/stdc++.h>

#define t (f (i, k) + f (k + 1, j) + arr [i].first * arr [k].second * arr [j].second)

void input ();
void solve ();

const int MAXN = 1e1 + 1, INF = 0x3f3f3f3f;

typedef std::pair <int, int> pi;

int n, cs;
pi arr [MAXN];
int dp [MAXN][MAXN], par [MAXN][MAXN];

int f (int i, int j) {
	if (dp [i][j] < INF)
		return dp [i][j];

	for (int k = i; k < j; k++) {
		if (dp [i][j] > t) {
			dp [i][j] = t;
			par [i][j] = k;
		}
	}
	//printf ("{%d, %d}: %d\n", i, j, dp [i][j]);
	return dp [i][j];
}

void print (int i, int j) {
	if (par [i][j]) {
		printf ("(");
		print (i, par [i][j]);
		printf (" x ");
		print (par [i][j] + 1, j);
		printf (")");
	}
	else
		printf ("A%d", i);
}

void input () {
	while (scanf ("%d", &n) && n != 0) {
		memset (dp, 0x3f, sizeof dp);
		memset (par, 0, sizeof par);
		for (int i = 1; i <= n; i++) {
			int a, b; scanf ("%d%d", &a, &b);
			arr [i] = {a, b};
			dp [i][i] = 0;
		}
		solve ();
	}
}

void solve () {
	// printf ("f: %d\n", f (0, n));
	f (1, n);
	printf ("Case %d: ", ++cs);
	print (1, n);
	puts ("");
}

int main () {
	input ();
	return 0;
}
