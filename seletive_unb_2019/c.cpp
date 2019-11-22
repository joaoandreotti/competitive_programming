#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;

const int MAXN = 1e5 + 1;

int n, q, m;
int arr [MAXN], aux [MAXN];
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
	scanf ("%d%d", &n, &q);
	init (n + 1);
	for (int i = 0; i < q; i++) {
		int a, b; scanf ("%d%d", &a, &b);
		// add dsu
		union_set (a, b);
	}
	scanf ("%d", &m);
	for (int i = 0 ; i < m; i++) {
		scanf ("%d", arr + i);
	}
	solve ();
}

void solve () {
	int dsu = 0;
	for (int i = 1; i <= n; i++)
		aux [find_set (p [i])] = 1;
	for (int i = 1; i <= n; i++)
		if (aux [i])
			dsu++;

	for (int i = 0; i < m; i++)
		aux [find_set (arr [i])]++;

	int know = 0;
	for (int i = 1; i <= n; i++)
		if (aux [i] > 1)
			know++;

	printf ("%d\n", dsu - know);
}

int main () {
	input ();
	return 0;
}
