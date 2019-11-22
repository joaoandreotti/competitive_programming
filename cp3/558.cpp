#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;

const int MAXN = 2e3 + 10;

int n, m, tc, cs;
vvpi g;
int dst [MAXN];

void input () {
	scanf ("%d", &tc);
	for (cs = 1; cs <= tc; cs++) {
		scanf ("%d%d", &n, &m);
		g.clear ();
		g.resize (n);
		memset (dst, 0x3f, sizeof dst);
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf ("%d%d%d", &a, &b, &c);
			g [a].push_back ({b, c});
		}
		solve ();
	}
}

void solve () {
	// bellman-ford
	
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			for (pi v : g [j])
				dst [v.first] = std::min (dst [v.first], dst [j] + v.second);

	int cycle = 0;
	for (int j = 0; j < n; j++)
		for (pi v : g [j])
			if (dst [v.first] > dst [j] + v.second)
				cycle = 1;
	if (cycle)
		puts ("possible");
	else
		puts ("not possible");
}

int main () {
	input ();
	return 0;
}
