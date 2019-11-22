#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;

const int MAXN = 2e5 + 1;

int n, m;
int arr [MAXN], vis [MAXN];
vi p, rank, set_size;

void init (int n) {
	set_size.assign (n, 1);
	rank.assign (n, 0);
	p.assign (n, 0);
	for (int i = 0; i < n; i++)
		p [i] = i;
}
int find_set (int i) {
	return (p [i] == i) ? i : (p [i] = find_set (p[i]));
}
bool same_set (int i, int j) {
	return find_set (i) == find_set (j);
}
void union_set (int i, int j) {
	if (!same_set (i, j)) {
		int x = find_set (i);
		int y = find_set (j);
		if (rank [x] > rank [y]) {
			p [y] = x;
			set_size [x] += set_size [y];
		}
		else {
			p [x] = y;
			set_size [y] += set_size [x];
			if (rank[x] == rank[y]) rank[y]++;
		}
	}
}

void input () {
	scanf ("%d%d", &n, &m);
	init (n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf ("%d", &a);
		if (a >= 1)
			scanf ("%d", &b);
		for (int j = 1; j < a; j++) {
			scanf ("%d", &c);
			union_set (b, c);
		}
	}
	solve ();
}

void solve () {
	for (int i = 1; i <= n; i++)
		if (i < n)
			printf ("%d ", set_size [find_set (i)]);
		else
			printf ("%d\n", set_size [find_set (i)]);
}

int main () {
	input ();
	return 0;
}
