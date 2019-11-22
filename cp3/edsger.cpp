#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <int> vi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;

const int MAXN = 1e3, INF = 0x3f3f3f3f;

int n, m;
vi dst;
vvpi g;
std::priority_queue <pi> pq;

void bfs (int x) {
	pq.push ({0, x});
	dst [x] = 0;
	while (!pq.empty ()) {
		pi top = pq.top (); pq.pop ();
    printf ("{%d, %d}\n", top.first, top.second);
		if (top.first > dst [top.second]) continue;

		for (pi i : g [top.second]) {
			if (dst [top.second] + i.first < dst [i.second]) {
				dst [i.second] = dst [top.second] + i.first;
				pq.push ({dst [i.second], i.second});
			}
		}
	}
}

void input () {
	scanf ("%d%d", &n, &m);
	g.resize (n);
	dst.assign (n, INF);

	for (int i = 0; i < m; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		g[a].push_back ({c, b});
		g[b].push_back ({c, a});
	}

	solve ();
}

void solve () {
  puts ("calling dijkstra");
	bfs (0);

	for (int i = 0; i < dst.size (); i++)
		printf ("0 -> %d = %d\n", i, dst [i]);
}

int main () {
	input ();
	return 0;
}
