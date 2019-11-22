#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 1e3;

int n, m, cs;
std::map <std::string, int> map1;
std::map <int, std::string> map2;
int inc [MAXN];
int visited [MAXN];
vi ans;
vvi g;

void bfs () {
	std::queue <int> q;
	for (int i = 0; i < n; i++)
		if (!inc [i])
			q.push (i);

	while (!q.empty ()) {
		int x = q.front (); q.pop ();
		printf ("x: {%d, %s}\n", x, map2 [x].c_str ());
		ans.push_back (x);
		for (int v : g [x]) {
			printf ("{inc [%d]: %d}", v, inc [v]);
			if (--inc [v] == 0)
				q.push (v);
			printf ("{inc [%d]: %d}", v, inc [v]);
			puts ("");
		}
	}
}

void bfs2 () {
	bool done = 0;
	while (!done) {
		done = true;
		for (int i = 0; i < n; i++) {
			if (inc [i] == 0 && !visited [i]) {
				done = false;
				visited [i] = 1;
				ans.push_back (i);
				for (int j = 0; j < g [i].size (); j++)
					inc [g [i][j]]--;
				i = -1;
			}
		}
	}
}

void bfs3 () {
	for (int i = 0; i < n; i++) {
		if (inc [i] == 0 && !visited [i]) {
			ans.push_back (i);
			visited [i] = 1;
			for (int v : g [i])
				inc [v]--;
			i = -1;
		}
	}
}

void input () {
	while (scanf ("%d", &n) != EOF) {
		std::string a, b;
		g.clear ();
		g.resize (n);
		map1.clear ();
		map2.clear ();
		ans.clear ();
		memset (inc, 0, sizeof inc);
		memset (visited, 0, sizeof visited);
		for (int i = 0; i < n; i++) {
			std::cin >> a;
			map1 [a] = i;
			map2 [i] = a;
		}
		scanf ("%d", &m);
		for (int i = 0; i < m; i++) {
			std::cin >> a >> b;
			g [map1 [a]].push_back (map1 [b]);
			inc [map1 [b]]++;
		}
		solve ();
	}
}

void solve () {
	bfs3 ();
	printf ("Case #%d: Dilbert should drink beverages in this order: ", ++cs);
	for (int i = 0; i < ans.size (); i++)
		if (i + 1 < ans.size ())
			printf ("%s ", map2 [ans [i]].c_str ());
		else
			printf ("%s.\n", map2 [ans [i]].c_str ());
	puts ("");
}

int main () {
	input ();
	return 0;
}
