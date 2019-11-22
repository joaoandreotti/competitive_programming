#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e2 + 1;

int n, l, f, c;
double arr [MAXN][MAXN];
double dp [MAXN][MAXN];

double func (int a, int v) {
	//printf ("{%d, %d}\n", a, v);
	
	if (dp [a][v])
		return dp [a][v];
	if (!v)
		return 1;

	for (int i = 0; i < n; i++) {
		if (i == f)
			continue;
		double tmp = arr [a][i];
		tmp *= func (i, v - 1);
		//printf ("{%d, %d} = %lF\n", a, v, tmp);
		dp [a][v] += tmp;
	}

	return dp [a][v];
}

void input () {
	scanf ("%d%d%d%d", &n, &l, &f, &c);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%lF", arr [i] + j);
	solve ();
}

void solve () {
	memset (dp, 0, sizeof dp);
	printf ("%lF\n", func (l, c));
}

int main () {
	input ();
	return 0;
}
