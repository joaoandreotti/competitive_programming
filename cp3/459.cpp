// ENTRADA LIXO, NAO FIZ ESSA QUESTAO
#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 26;

int t, visited [MAXN];
char n;
vvi g;

void dfs (int x) {
	//printf ("%d ", x);
	visited [x] = 1;
	for (int v : g [x])
		if (!visited [v])
			dfs (v);
}

void input () {
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf (" %c", &n);
		n -= 'A';
		g.clear ();
		//printf ("n: %d\n", (int) n);
		g.resize ((int) n + 1);
		char a, b;
		for (int i = 0; i < (int) n; i++) {
			scanf (" %c%c", &a, &b);
			a -= 'A';
			b -= 'A';
			//printf ("a: %d, b: %d\n", (int) a, (int) b);
			g [(int) a].push_back ((int) b);
			g [(int) b].push_back ((int) a);
		}
		solve ();
	}
}

void solve () {
	long long ans = 0;
	for (int i = 0; i < (int) n; i++) {
		if (!visited [i]) {
			//printf ("cc %d:", ++ans);
			ans++;
			dfs (i);
			//puts ("");
		}
	}
	printf ("%lld\n", ans);
}

int main () {
	input ();
	return 0;
}
