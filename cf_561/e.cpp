#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXM = (1e2 + 2) / 2, MAXN = 1e4 + 1;

int m, n;
int g [MAXM][MAXN];

void input () {
	scanf ("%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
		int a; scanf ("%d", &a);
		for (int j = 0; j < a; j++) {
			int b; scanf ("%d", &b);
			g [i][b] = 1;
		}
	}
	solve ();
}

void solve () {
	int flag = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int x = 0;
			for (int k = 0; k < n; k++)
				if (g [i][k] && g [j][k])
					x = 1;
			if (!x)
				flag = 0;
		}
	}
	if (flag)
		puts ("possible");
	else
		puts ("impossible");
}

int main () {
	input ();
	return 0;
}
