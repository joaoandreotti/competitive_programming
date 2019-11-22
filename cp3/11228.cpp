#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::pair <double, pi> pip;
typedef std::vector <pip> vpip;
typedef std::vector <int> vi;

const int MAXN = 1e3 + 10;

int t, cs, n, m;
vpip g, edges;
vi p, rank, size, vis;

double dst (pi a, pi b) {
	return sqrt ((abs (a.first - b.first) * abs (a.first - b.first)) + (abs (a.second - b.second) * abs (a.second - b.second)));
}

int find (int i) {
	return p [i] == i ? i : p [i] = find (p[i]);
}

int same (int i, int j) {
	return find (i) == find (j);
}

int add (int i, int j) {
	if (!same (i, j)) {
		int x = find (i);
		int y = find (j);
		if (rank [x] > rank [y]) {
			p [y] = x;
			size [x] += size [y];
		}
		else {
			p [x] = y;
			size [y] += size [x];
			if (rank [x] == rank [y])
				rank [y]++;
		}
		return 1;
	}
	return 0;
}

void input () {
	scanf ("%d", &t);
	for (cs = 1; cs <= t; cs++) {
		scanf ("%d%d", &n, &m);
		// clear
		g.clear ();
		edges.clear ();
		// assign
		p.assign (n, 0);
		rank.assign (n, 0);
		size.assign (n, 1);
		vis.assign (n, 0);
		for (int i = 0; i < n; i++)
			p [i] = i;

		for (int i = 0; i < n; i++) {
			int a, b; scanf ("%d%d", &a, &b);
			g.push_back ({i, {a, b}});
		}
		solve ();
	}
}

void solve () {
	for (auto i : g)
		for (auto j : g)
			if (i.first != j.first)
				edges.push_back ({dst (i.second, j.second), {i.first, j.first}});
	
	//for (auto i : edges)
		//printf ("{%d, {%d, %d}}\n", i.first, i.second.first, i.second.second);

	std::sort (edges.begin (), edges.end ());

	// kruskal
	double states = 1, r = 0, rr = 0;
	for (auto i : edges) {
		if (add (i.second.first, i.second.second)) {
			if (i.first <= m)
				r += i.first;
			else {
				rr += i.first;
				states++;
			}
		}
	}
	long long a = round (states), b = round (r), c = round (rr);

	printf ("Case #%d: %lld %lld %lld\n", cs, a, b, c);
}

int main () {
	input ();
	return 0;
}
