#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <int> vi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;
typedef std::priority_queue <pi> pqi;

const int INF = 0x3f3f3f3f;

int n, m, q, f, s, e;
vi gs, dst;
vvpi g;
pqi pq;

void bfs () {
	pq.push ({0, s});
	dst [s] = 0;
	while (!pq.empty ()) {
		pi top = pq.top (); pq.pop ();
		if (dst [top.second] < top.first) continue;

		for (pi v : g [top.second]) {
			if (f <=  && dst [top.second] + v.first < dst [v.second]) {
				dst [v.second] = dst [top.second] + v.first;
				pq.push ({dst [v.second], v.first});
			}
		}
	}
}

void input () {
	scanf ("%d%d", &n, &m);
	gs.clear ();
	pq.clear ();
	g.clear ();
	dst.clear ();
	g.resize (n);
	dst.assign (0, INF);
	for (int i = 0; i < n; i++) {
		int a; scanf ("%d", &a);
		gs.push_back (a);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		g [a].push_back ({c, b});
		g [b].push_back ({c, a});
	}
	scanf ("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf ("%d%d%d", &f, &s, &e);
		solve ();
	}
}

void solve () {
}

int main () {
	return 0;
}
