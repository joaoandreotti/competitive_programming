#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 2e2 + 1;

int n, m;
vvi g;
int visited [MAXN];

bool bfs (int s) {
	int ans = 1;
	std::queue <int> q; q.push (s);
	visited [s] = 0;
	while (!q.empty () && ans) {
		int x = q.front (); q.pop ();
		for (int v : g [x]) {
			if (visited [v] == -1) {
				visited [v] = 1 - visited [x];
				q.push (v);
			}
			else if (visited [v] == visited [x])
				ans = 0;
		}
	}
	return ans;
}

bool dfs (int x, int f) {
	visited [x] = 1 - visited [f];
	int ans = 1;
	for (int v : g [x]) {
		if (visited [v] == -1)
			dfs (v, x);
		else if (visited [v] == visited [x])
			return false;
	}
	return true;
}

void input () {
	while (scanf ("%d", &n) && n != 0) {
		scanf ("%d", &m);
		g.clear ();
		g.resize (n);
		memset (visited, -1, sizeof visited);
		for (int i = 0; i < m; i++) {
			int a, b; scanf ("%d%d", &a, &b);
			g [a].push_back (b);
			g [b].push_back (a);
		}
		solve ();
	}
}

void solve () {
	if (!dfs (0, 0))
		puts ("NOT BICOLORABLE.");
	else
		puts ("BICOLORABLE.");
}

int main () {
	input ();
	return 0;
}
