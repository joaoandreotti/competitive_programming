#include <bits/stdc++.h>

void input ();
void solve ();

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e2 + 10;

typedef long long ll;
typedef long double ld;

int n, k;
ll arr [MAXN][MAXN];
int vis [MAXN];


void input () {
	scanf ("%d%d", &n, &k);
	memset (arr, 0x3f, sizeof arr);
	for (int i = 0; i < k; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		a--; b--;
		if (arr [a][b] > c)
			arr [a][b] = c;
	}
	solve ();
}

void solve () {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr [i][j] = std::min (arr [i][j], arr [i][k] + arr [k][j]);

	ld ans = 0, p = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && arr [i][j] != INF) {
				ans += arr [i][j];
				p++;
			}
	printf ("%Lf\n", ans / p);
}

int main () {
	input ();
	return 0;
}
