#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::string ss;
typedef std::map <ss, int> msi;
typedef std::vector <ss> vs;
typedef std::set <int> si;
typedef std::vector <int> vi;
typedef std::vector <si> vsi;

const int MALP = 26;

vs in;
msi map;
vsi g;
int vis [MALP], ex [MALP];

void dfs (int x) {
	printf ("%c ", x + 'A');
	vis [x] = 1;
	for (auto v : g [x])
		if (!vis [v])
			dfs (v);
}

void input () {
	ss str;
	while (std::cin >> str)
		in.push_back (str);
	solve ();
}

void solve () {
	g.resize (MALP);
	for (int i = 0; i < in.size (); i++) {
		if (in [i].size ())
			ex [in [i][0] - 'A'] = 1;
		for (int j = 0; j < in [i].size () - 1; j++) {
			int a = in [i][j] - 'A', b = in [i][j + 1] - 'A';
			g [a].insert (b);
			//g [b].insert (a);
			ex [a] = 1;
			//ex [b] = 1;
		}
	}

	for (int i = 0; i < g.size (); i++) {
		if (!vis [i] && ex [i]) {
			dfs (i);
			puts ("");
		}
	}
}

int main () {
	input ();
	return 0;
}
