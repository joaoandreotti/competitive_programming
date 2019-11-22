#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::pair <int, pi> pipi;
typedef std::vector <int> vi;
typedef std::vector <pipi> vpi;

const int MAXN = 1e2 + 1;

vpi edges;
vi p, rank, size;
int n, m;
int visited [MAXN];
std::priority_queue <pi> pq;

int find (int i) {
	return (p [i] == i) ? i : p [i] = find (p [i]); // path compression
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

void kruskal () {
	std::sort (edges.begin (), edges.end ());
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		if (add (edges [i].second.first, edges [i].second.second)) {
			//printf ("{%d, %d}\n", edges [i].second.first, edges [i].second.second);
			ans += edges [i].first;
		}
	}
	printf ("%lld\n", ans);
}

void aux (int s) {
	visited [s] = 1;
	for (int i = 0; i < m; i++)
		if (edges [i].second.first == s && !visited [edges [i].second.second])
			pq.push ({-edges [i].first, -edges [i].second.second});
		else if (edges [i].second.second == s && !visited [edges [i].second.first])
			pq.push ({-edges [i].first, -edges [i].second.first});
}

void prim (int s) {
	long long ans = 0;

	aux (s);
	while (!pq.empty ()) {
		pi top = pq.top (); pq.pop ();
		printf ("{%d, %d}\n", -top.first, -top.second);
		if (!visited [-top.second]) {
			ans += -top.first;
			aux (-top.second);
		}
	}
	printf ("%lld\n", ans);
}

void input () {
	scanf ("%d%d", &n, &m);
	// n++; if starts from 1
	edges.clear ();
	size.clear ();
	rank.clear ();
	p.clear ();
	size.assign (n, 1);
	rank.assign (n, 0);
	p.assign (n, 0);
	for (int i = 0; i < n; i++)
		p [i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		edges.push_back ({c, {a, b}});
	}
	solve ();
}

void solve () {
	prim (0);
}

int main () {
	input ();
	return 0;
}
