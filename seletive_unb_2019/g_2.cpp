#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::map <std::string, int> msi;
typedef std::map <int, std::string> mis;
typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

int n, m;
msi map;
mis rev;
vi arr, used;
vvi g;

void input () {
	scanf ("%d%d", &n, &m);
	g.resize (n);
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		map [str] = i;
		rev [i] = str;
	}
	for (int i = 0; i < m; i++) {
		std::string a, b;
		std::cin >> a >> b;
		g [map [a]].push_back (map [b]);
		g [map [b]].push_back (map [a]);
	}
	solve ();
}

void solve () {
	for (int i = 0; i < (1 << n); i++) {
		arr.push_back (i);
		int count = 0;
		for (int j = n - 1; j >= 0; j--)
			if ((i >> j) & 1)
				count++;
		used.push_back (count);
	}
	long long ans = LONG_MAX;
	int nds;
	for (int i = 0; i < arr.size (); i++) {
		int x = arr [i];
		for (int j = n - 1; j >= 0; j--) {
			if ((x >> j) & 1) {
				for (int v : g [j]) {
					arr [i] |= 1 << v;
				}
			}
		}
		if (arr [i] == ((1 << n) - 1)) {
			if (ans > used [i]) {
				ans = used [i];
				nds = x;
			}
		}
	}
	printf ("%lld\n", ans);
	int count = 0;
	std::string str [18];
	for (int j = n - 1; j >= 0; j--)
		if ((nds >> j) & 1)
			str [count++] = rev [j];
	for (int i = 0; i < count; i++)
		if (i + 1 < count)
			std::cout << str [i] << " ";
		else
			std::cout << str [i] << "\n";
}

int main () {
	input ();
	return 0;
}
