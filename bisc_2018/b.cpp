#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

int n, m;
int match [251], vis [251];
vvi g;
vpi ans;

bool dfs (int x) {
	if (vis [x])
		return 0;
	vis [x] = 1;
	for (auto v : g [x]) {
		if (match [v] == -1 || dfs (match [v])) {
			match [v] = x;
			return 1;
		}
	}

	return 0;
}

void input () {
	scanf ("%d%d", &n, &m);
	g.resize (n);
	memset (match, -1, sizeof match);
	for (int i = 0; i < n; i++) {
		while (1) {
			int a; scanf ("%d", &a);
			if (a)
				g [i].push_back (a - 1);
			else
				break;
		}
	}
	solve ();
}

void solve () {
	for (int i = 0; i < n; i++) {
		memset (vis, 0, sizeof vis);
		dfs (i);
	}

	for (int i = 0; i < m; i++)
		if (match [i] != -1)
			ans.push_back ({match [i], i});

	printf ("%d\n", (int) ans.size ());
	for (int i = 0; i < ans.size (); i++)
		printf ("%d %d\n", ans [i].first + 1, ans [i].second + 1);

}

int main () {
	input ();
	return 0;
}

