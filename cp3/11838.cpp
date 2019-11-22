#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 2e3 + 10;

int n, m, rch, root, nmb, edges;
vvi g;
vi stk;
int num [MAXN], low [MAXN], visited [MAXN];

int dfs (int x, int f) {
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

void cp3_dfs (int x) {
	num [x] = ++rch;
	low [x] = num [x];
	visited [x] = 1;
	stk.push_back (x);

	for (int v : g [x]) {
		if (num [v] == -1)
			cp3_dfs (v);
		if (visited [v])
			low [x] = std::min (low [x], low [v]);
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
}

void naive (int x) {
	visited [x] = 1;
	for (int v : g [x])
		if (!visited [v])
			naive (v);
}

void input () {
	while (scanf ("%d%d", &n, &m) && n && m) {
		g.clear ();
		stk.clear ();
		g.resize (n);
		memset (num, -1, sizeof num);
		memset (low, 0, sizeof low);
		memset (visited, 0, sizeof visited);
		nmb = 0;
		edges = 0;
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf ("%d%d%d", &a, &b, &c);
			a--; b--;
			edges++;
			g [a].push_back (b);
			if (c == 2) {
				edges++;
				g [b].push_back (a);
			}
		}
		solve ();
	}
}

void solve () {
	/*
	int flag;
	for (int i = 0; i < n; i++) {
		flag = 1;
		memset (visited, 0, sizeof visited);
		naive (i);
		for (int j = 0; j < n; j++)
			if (visited [j] == 0)
				flag = 0;
		if (!flag)
			break;
	}
	if (flag)
		puts ("1");
	else
		puts ("0");
		*/

	for (int i = 0; i < n; i++)
		if (num [i] == -1)
			dfs (i, i);
	//printf ("%d\n", nmb);
	if (nmb - 1)
		puts ("0");
	else
		puts ("1");
}

int main () {
	input ();
	return 0;
}
