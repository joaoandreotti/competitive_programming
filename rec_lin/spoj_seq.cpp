#include <bits/stdc++.h>

#define MOD (int)(1e9)

typedef long long ll;

const int MAXN = 1e1 + 1;

void input ();
void solve ();

ll tc, k, n;
ll b [MAXN], c [MAXN];

typedef struct matrix {
	ll m [MAXN][MAXN];

	matrix () {
		memset (m, 0, sizeof m);
	}

	matrix operator* (matrix a) {
		matrix c = matrix ();
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++) {
				for (int l = 0; l < k; l++)
					c.m [i][j] += (m [i][l] * a.m [l][j]) % MOD;
				c.m [i][j] %= MOD;
			}
		return c;
	}
} matrix;

matrix unit;

matrix f (matrix a, ll e) {
	if (e == 1)
		return a;

	matrix h = f (a, e / 2);
	matrix out = h * h;
	if (e % 2)
		out = out * a;
	return out;
}

void input () {
	scanf ("%lld", &tc);
	while (tc--) {
		scanf ("%lld", &k);
		for (int i = 0; i < k; i++)
			scanf ("%lld", b + i);
		for (int i = 0; i < k; i++)
			scanf ("%lld", c + i);
		scanf ("%lld", &n);
		solve ();
	}
}

void solve () {
	unit = matrix ();
	for (int i = 0; i < k; i++)
		unit.m [i][i] = 1;

	matrix t = matrix ();
	for (int i = 1; i < k; i++)
		t.m [i - 1][i] = 1;
	for (int i = 0; i < k; i++)
		t.m [k - 1][i] = c [k - i - 1];

	matrix a = f (t, n - 1);

	/*
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++)
			printf ("%lld ", a.m [i][j]);
		puts ("");
	}
	*/
	long long ans = 0;
	for (int i = 0; i < k; i++)
		ans = (ans + a.m [0][i] * b [i]) % MOD;
	printf ("%lld\n", ans);
}

int main () {
	input ();
	return 0;
}
