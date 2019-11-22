#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 1e3;

int n, m;
int visited [MAXN];
int inc [MAXN], out [MAXN];
vi ans;
vvi g;

// the idea of topological sort is to always remove the TOP first, which could be more than 1
// but everytime that a TOP is removed we get the next TOP
// TOP == vertices which has no incoming edges

void dfs (int x) {
	visited [x] = 1;
	for (int v : g [x])
		if (!visited [v])
			dfs (v);
	ans.push_back (x);
}

void bfs () {
	std::queue <int> q;
	for (int i = 0; i < n; i++)
		if (!inc [i])
			q.push (i);

	while (!q.empty ()) {
		int x = q.front (); q.pop ();
		ans.push_back (x);
		for (int v : g [x])
			if (--inc [v] == 0)
				q.push (v);
	}
}

void input () {
	scanf ("%d%d", &n, &m);
	g.clear ();
	g.resize (n);
	for (int i = 0; i < m; i++) {
		int a, b; scanf ("%d%d", &a, &b);
		g [a].push_back (b);
		out [a]++;
		inc [b]++;
	}
}

void solve () {
	/*
	for (int i = 0; i < n; i++)
		if (!visited [i])
			dfs (i);
	for (int i = ans.size () - 1; i >= 0; i--)
		printf ("%d ", ans [i]);
	puts ("");
	*/

	bfs ();
	for (int i = 0; i < ans.size (); i++)
		printf ("%d ", ans [i]);
	puts ("");
}

int main () {
	input ();
	solve ();
	return 0;
}
