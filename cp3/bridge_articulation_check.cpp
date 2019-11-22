#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 1e2 + 1;

int n, m, rch, root;
vvi g;
vi stk;
int num [MAXN], low [MAXN], visited [MAXN];


// if num [x] <= low [v] it means that V cannot reach a vertex
// with num [w] <= num [x] so by removing vertex V the graph become
// disconect because V cannot reach X, so X is an articulation point.
//
// if num [x] < low [v] it means that edge {X, V} is a bridge becouse
// when that edge {X, V} is removed an ancestor os X is still reachable
// by V.
int dfs (int x, int f) {
	num [x] = ++rch;
	low [x] = num [x];
	for (int v : g [x]) {
		if (!num [v])
			low [x] = std::min (dfs (v, x), low [x]);
		if (v != f) {
			low [x] = std::min (low [v], low [x]);
			low [f] = std::min (low [x], low [f]);
		}
		// if can be chanced so that never prints more than one time
		// the same articulation vertex
		if (num [x] <= low [v]) {
			if (x != root)
				printf ("%d is an articulation vertex.\n", x);
			if (num [x] != low [v])
				printf ("{%d, %d} is a bridge.\n", x, v);
		}
	}
	return num [x];
}

int dfsSCC (int x, int f) {
	num [x] = ++rch;
	low [x] = num [x];
	visited [x] = 1;
	stk.push_back (x);

	for (int v : g [x]) {
		if (!visited [v])
			dfs (v, x);
		if (visited [v])
			low [x] = std::min (low [v], low [x]);
	}

	if (low [x] == num [x]) {
		nmb++;
		while (true) {
			int t = stk.back ();
			stk.pop_back ();
			visited [t] = 0;
			if (x == t)
				break;
		}
	}

	return num [x];
}

void cp3_dfs (int u, int f) {
	low [u] = num [u] = ++rch;

	for (int v : g [u]) {
		if (!num [v]) {
			dfs (v, u);
			if (num [u] <= low [v]) {
				if (u != root)
					printf ("%d is an articulation vertex.\n", u);
				if (num [u] != low [v])
					printf ("{%d, %d} is a bridge.\n", u, v);
			}
			low [u] = std::min (low [u], low [v]);
		}
		else if (v != f)
			low [u] = std::min (low [u], num [v]);
	}
}

void input () {
	scanf ("%d%d", &n, &m);
	g.clear ();
	g.resize (n);
	for (int i = 0; i < m; i++) {
		int a, b; scanf ("%d%d", &a, &b);
		g [a].push_back (b);
		g [b].push_back (a);
	}
	solve ();
}

void solve () {
	cp3_dfs (root, root);

	for (int i = 0; i < n; i++)
		printf ("%d = {%d, %d}\n", i, num [i] - 1, low [i] - 1);
}

int main () {
	input ();
	return 0;
}
