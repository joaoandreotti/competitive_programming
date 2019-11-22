#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::map <std::string, int> msi;
typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int INF = 0x3f3f3f3f;

int n, m, iftd;
int count = 0;
msi in;
vvi g;
int vis [19];

int f (int x, int iftd) {
	vis [x] = 1;
	iftd |= 1 << x;
	for (int v : g [x])
		iftd |= 1 << v;

	printf ("x: %d, iftd: ", x);
	for (int i = n - 1; i >= 0; i--)
		printf ("%d", (iftd >> i) & 1);
	puts ("");

	for (int v : g [x])
		if (!vis [v]) {
			if (iftd != f (v, iftd))
				count++;
			iftd = f (v, iftd);
		}
	return iftd;
}

void input () {
	scanf ("%d%d", &n, &m);
	g.resize (n);
	for (int i = 0; i < n; i++) {
		std::string a;
		std::cin >> a;
		in [a] = i;
	}
	for (int i = 0; i < m; i++) {
		std::string a, b;
		std::cin >> a >> b;
		g [in [a]].push_back (in [b]);
		g [in [b]].push_back (in [a]);
	}
	solve ();
}

void solve () {
	memset (vis, 0, sizeof vis);
	for (int i = 0; i < n; i++) {
		if (!vis [i])
			printf ("f (%d, %d): %d\n", i, iftd, iftd = f (i, iftd));
	}
}

int main () {
	input ();
	return 0;
}
