#include <bits/stdc++.h>

#define y1 aosidjfiasodjfoisajdfoiasdjf

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 40 + 1;
const int MAXN2 = (40 * 40) + 1;

int px [4] = {1, -1, 0, 0}, py [4] = {0, 0, 1, -1};

int n, p;
int match [MAXN2], vis [MAXN2];
int cb [MAXN][MAXN];
vvi g;
vpi ans;

bool dfs (int x) {
	if (vis [x])
		return 0;
	vis [x] = 1;
	//printf ("dfs (%d): %d, %d\n", x, p, v.first);
	for (auto v : g [x]) {
		if (match [v] == -1 || dfs (match [v])) {
			match [v] = x;
			return 1;
		}
	}

	return 0;
}

void add (int x) {
	int i = x / n;
	int j = x % n;
	//printf ("adding {%d, %d}: ", i, j);
	if (cb [i][j] || (i + j) % 2) {
		//puts ("");
		return;
	}
	for (int k = 0; k < 4; k++)
		if (px [k] + i >= 0 && px [k] + i < n &&
				py [k] + j >= 0 && py [k] + j < n &&
				!cb [px [k] + i][py [k] + j]) {
			//printf ("{%d, %d}", px [k] + i, py [k] + j);
			g [x].push_back (((px [k] + i) * n) + (py [k] + j));
		}
}

void input () {
	scanf ("%d%d", &n, &p);
	for (int i = 0, a, b; i < p; i++) {
		scanf ("%d%d", &a, &b);
		cb [b - 1][a - 1] = 1;
	}
	solve ();
}

void solve () {
	g.resize (n * n);
	memset (match, -1, sizeof match);
	for (int i = 0; i < (n*n); i++)
		add (i);

	/*
	for (int i = 0; i < g.size (); i++) {
		printf ("%d: ", i);
		for (int j = 0; j < g [i] .size (); j++)
			printf ("%d ", g [i][j]);
		puts ("");
	}
	*/

	for (int i = 0; i < (n * n); i++) {
		memset (vis, 0, sizeof vis);
		dfs (i);
	}

	vpi hor, ver;

	for (int k = 0; k < (n * n); k++)
		if (match [k] != -1) {
			int x1 = (k % n) + 1, y1 = (k / n) + 1;
			int x2 = (match [k] % n) + 1, y2 = (match [k] / n) + 1;
			pi lm = std::min (std::make_pair (x1, y1), std::make_pair (x2, y2));
			if (y1 == y2)
				hor.push_back (lm);
			else
				ver.push_back (lm);
		}

	if (((hor.size () + ver.size ()) * 2) == ((n * n) - p)) {
		puts ("Yes");
		printf ("%d\n", (int)hor.size ());
		std::sort (hor.begin (), hor.end ());
		std::sort (ver.begin (), ver.end ());
		for (int i = 0; i < hor.size (); i++)
			printf ("%d %d\n", hor [i].first, hor [i].second);

		printf ("%d\n", (int)ver.size ());
		for (int i = 0; i < ver.size (); i++)
			printf ("%d %d\n", ver [i].first, ver [i].second);
	}
	else
		puts ("No");
}

int main () {
	input ();
	return 0;
}
