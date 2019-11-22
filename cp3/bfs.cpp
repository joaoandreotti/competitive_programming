#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;
typedef std::queue <int> qi;

const int MAXN = 1e3;

int n;
vvi g;
int visited [MAXN];

void bfs (int x) {
	printf ("x: %d", x);
	qi q;
	q.push (x);
	//memset (visited, -1, sizeof visited);
	visited [x] = 1;
	while (!q.empty ()) {
		int nd = q.front (); q.pop ();
		for (int v : g [nd]) {
			if (!visited [v]) {
				visited [v] = visited [nd] + 1;
				q.push (v);
			}
		}
	}
}

void input () {
	scanf ("%d", &n);
	g.resize (n + 1);
	for (int i = 0; i <= n; i++) {
		int a, b; scanf ("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf ("%d", &b);
			g [i].push_back (b);
		}
	}
}

void solve () {
	for (int i = 0; i < g.size (); i++) {
		for (int j = 0; j < g [i].size (); j++)
			printf ("%d ", g [i][j]);
		puts ("");
	}
	bfs (5);
	for (int i = 0; i < g.size (); i++) {
		printf ("i: %d => ", i);
		for (int j = 0; j < g.size (); j++)
			if (visited [j] == i)
				printf ("%d ", j);
		puts ("");
	}
}

int main () {
	input ();
	solve ();
	return 0;
}
