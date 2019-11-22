#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::pair <int, pi> pipi;
typedef std::vector <int> vi;
typedef std::vector <pipi> vpi;

const int MAXN = 1e5 + 1;

vpi edges;
vi p, rank, size;
int n, m;
int visited [MAXN];
long long glb_ans;
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

void clear_dsu () {
  size.clear ();
  rank.clear ();
  p.clear ();

	size.assign (n, 1);
	rank.assign (n, 0);
	p.assign (n, 0);

  for (int i = 0; i < n; i++)
    p [i] = i;
}

int kruskal (int flag, int b) {
  if (flag)
    std::sort (edges.begin (), edges.end ());

	long long ans = 0;
  int count = 0;
	for (int i = 0; i < m; i++) {
		if (i != b && add (edges [i].second.first, edges [i].second.second)) {
      if (flag)
        visited [i] = 1;
			//printf ("{%d, %d}\n", edges [i].second.first, edges [i].second.second);
			ans += edges [i].first;
      count++;
		}
	}


  if (count != n-1)
    return -1;

	//printf ("%lld\n", ans);
  return ans;
}

long long sec_mst () {
  long long tmp = LLONG_MAX;
  for (int i = 0; i < m; i++) {
    if (visited [i]) {
      clear_dsu ();
      long long x = kruskal (0, i);
      if (x != -1 && x != glb_ans)
        tmp = std::min (tmp, x);
    }
  }

  return tmp;

}

void input () {
  scanf ("%d%d", &n, &m);
	size.assign (n, 1);
	rank.assign (n, 0);
	p.assign (n, 0);

  for (int i = 0; i < n; i++)
    p [i] = i;

  for (int i = 0, a, b, c; i < m && scanf ("%d%d%d", &a, &b, &c); i++) {
    a--; b--;
		edges.push_back ({c, {a, b}});
  }
  solve ();
}

void solve () {
  glb_ans = kruskal (1, -1);

  long long ans = sec_mst ();
  if (ans != LLONG_MAX)
    printf ("%lld\n", ans);
  else
    printf ("%d\n", -1);

}

int main () {
  input ();
  return 0;
}
