#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;
typedef std::vector <int> vi;

const int MAXN = 1e3, INF = 0x3f3f3f3f;

int n, m, f, s, t;
vvpi g;
int res [MAXN][MAXN];
vi bst;

void augmented_path (int v, int min) {
	if (v == s) f = min;
	else if (bst [v] != -1) {
		// augmented_path (father of V, (min_edge (maximum flow) between the current MIN and the edge {bst [v] -> v}));
		augmented_path (bst [v], std::min (min, res [bst [v]][v]));
		// F is a global variable which stores the min_edge (maximum_flow) on the
		// bsf spanning tree
		res [bst [v]][v] -= f;
		res [v][bst [v]] += f;
	}
}

void ek () {
	int ans = 0;

	while (1) {
		f = 0;
		vi dst (n, INF); dst [s] = 0;
		std::queue <int> q;
		q.push (s);
		bst.assign (n, -1);
		// run bfs
		// bst [X] stores the father of X
		// on the bfs spanning tree
		while (!q.empty ()) {
			int u = q.front (); q.pop ();
			if (u == t) break;

			for (int v = 0; v < n; v++) {
				// if there is unused capacity and
				// v was not visited yet
				if (res [u][v] > 0 && dst [v] == INF) {
					dst [v] = dst [u] + 1;
					q.push (v);
					bst [v] = u;
				}
			}
		}
		// find a augmented path if exists
		augmented_path (t, INF);
		if (f == 0) break;
		ans += f;
	}
	printf ("ans: %d\n", ans);
}

void input () {
	scanf ("%d%d", &n, &m);
	scanf ("%d%d", &s, &t);
	g.clear ();
	g.resize (n);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		g [a].push_back ({b, c});
		res [a][b] = c;
	}
	solve ();
}

void solve () {
	ek ();
}

int main () {
	input ();
	return 0;
}
