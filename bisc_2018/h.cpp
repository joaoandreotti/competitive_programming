#include <bits/stdc++.h>

#define y1 oajsdfopasjdfopjasdfopjasdfopjsadfopk

void input ();
void solve ();

const int MAXN = 101, INF = 0x3f3f3f3f;

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::queue <pi> qpi;

int m, n, p, q, x1, y1, x2, y2;
pi dst [MAXN][MAXN];
qpi bfs;
vpi ans;

bool rec (int x, int y) {
	if (x == 0 || y == 0) {
		return true;
	}
	if (x == INF || y == INF)
		return false;
	ans.push_back ({x, y});
	return rec (dst [x][y].first, dst [x][y].second);
}

void input () {
	scanf ("%d%d%d%d%d%d%d%d", &m, &n, &p, &q, &x1, &y1, &x2, &y2);
	for (int i = 0; i <= std::max (n, m); i++) {
		for (int j = 0; j <= std::max (n, m); j++)
			dst [i][j] = std::make_pair (INF, INF);

	}
	solve ();
}

void solve () {
	int arr1 [8] = {p, p, -p, -p, q, q, -q, -q};
	int arr2 [8] = {q, -q, -q, q, p, -p, -p, p};


	bfs.emplace (x1, y1);

	dst [x1][y1] = std::make_pair (0, 0);
	while (!bfs.empty ()) {
		//printf ("{%d, %d}\n", bfs.front ().first, bfs.front ().second);
		pi top = bfs.front ();
		int x = top.first;
		int y = top.second;
		bfs.pop ();

		for (int i = 0; i < 8; i++) {
			if (arr1 [i] + x >= 1 && arr1 [i] + x <= m)
				if (arr2 [i] + y >= 1 && arr2 [i] + y <= n)
					if (dst [arr1 [i] + x][arr2 [i] + y].first == INF) {
						dst [arr1 [i] + x][arr2 [i] + y] = std::make_pair (x, y);
						bfs.emplace (arr1 [i] + x, arr2 [i] + y);
					}
		}

	}
	if (rec (x2, y2)) {
		printf ("%d\n", (int) ans.size () - 1);
		std::reverse (ans.begin (), ans.end ());
		for (int i = 0; i < ans.size (); i++)
			printf ("%d %d\n", ans [i].first, ans [i].second);
	}
	else
		puts ("-1");
}

int main () {
	input ();
	return 0;
}
