#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;

const int MAXN = 1e2 + 1;

int n, m;
vvpi g;
int dst [MAXN], INF = 0x3f3f3f3f;

void bl (int s) {
	dst [s] = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			for (pi v : g [j])
				dst [v.first] = std::min (dst [v.first], dst [j] + v.second);

}

void input () {
	scanf ("%d%d", &n, &m);
	g.resize (n);
	memset (dst, 0x3f, sizeof dst);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		g [a].push_back ({b, c});
	}
	solve ();
}

void solve () {
	bl (0);
	for (int i = 0; i < n; i++)
		printf ("%d ", dst [i]);
	puts ("");
}

int main () {
	input ();
	return 0;
}
