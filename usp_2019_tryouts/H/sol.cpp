#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::bitset <100> bs;
typedef std::vector <bs> vbs;

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;

typedef long double lf;

const int MAXN = 1e2 + 1;
const lf INF = 1e18L;
const lf EPS = 1e-9;

int n, m;
vvpi st, cs;
lf dst [MAXN][MAXN];

bool cmp (pi a, int b) {
	return a.first < b;
}

bool cmp1 (pi a, pi b) {
	return std::make_pair (a.second, a.first) > std::make_pair (b.second, b.first);
}

void input () {
	scanf ("%d%d", &n, &m);
	st.resize (n);
	cs.resize (m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dst [i][j] = INF;
	for (int i = 0, q; i < n; i++) {
		scanf ("%d", &q);
		for (int j = 0, a, b; j < q; j++) {
			scanf ("%d%d", &a, &b);
			a--;
			st [i].push_back ({a, b});
			cs [a].push_back ({i, b});
		}
	}
	solve ();
}

void solve () {
	for (int i = 0; i < st.size (); i++)
		std::sort (st [i].begin (), st [i].end ());

	for (int i = 0; i < st.size (); i++) {
		for (int j = 0; j < st.size (); j++) {
			if (i != j) {
				int flag = 0;
				for (int k = 0; k < st [i].size (); k++) {
					int f = 0;
					pi x;
					for (int l = 0; l < st [j].size (); l++)
						if (st [j][l].first == st [i][k].first) {
							f = 1;
							x = st [j][l];
						}
					if (f) {
						if (!flag)
							dst [i][j] = 0;
						//printf ("{%d, %d}, {%d, %d}\n", st [i][k].first, st [i][k].second, x->first, x->second);
						dst [i][j] += std::abs (st [i][k].second - x.second) * std::abs (st [i][k].second - x.second);
						flag = 1;
					}
				}
				if (flag)
					dst [i][j] = sqrtl (dst [i][j]);
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (dst [i][j] != INF)
				printf ("%Lf ", dst [i][j]);
			else
				printf ("inf ");
		puts ("");
	}
	*/

	for (int i = 0; i < st.size (); i++) {
		int bf = -1;
		lf max = 0;
		for (int j = 0; j < n; j++)
			if (dst [i][j] != INF && dst [i][j] - max > EPS) {
				max = dst [i][j];
				bf = j;
			}
		if (bf == -1)
			puts ("-1");
		else {
			std::sort (st [bf].begin (), st [bf].end (), cmp1);
			std::sort (st [i].begin (), st [i].end (), cmp1);
			int flag = 0, ans;
			//printf ("i: %d, bf: %d\n", i, bf);
			for (int j = 0; j < st [bf].size (); j++) {
				//printf ("{%d, %d}\n", st [bf][j].first + 1, st [bf][j].second);
				int f = 0;
				for (int k = 0; k < st [i].size (); k++)
					if (st [bf][j].first == st [i][k].first)
						f = 1;
				if (!f) {
					//printf ("f{%d, %d}\n", st [bf][j].first + 1, st [bf][j].second);
					flag = 1;
					ans = st [bf][j].first + 1;
					break;
				}
			}
			//puts ("");
			if (flag)
				printf ("%d\n", ans);
			else
				puts ("-1");
		}
	}
}

int main () {
	input ();
	return 0;
}

/*
   auto x = std::lower_bound (st [i].begin (), st [i].end (), st [bf][j].first, cmp);
   if (x == st [i].end () || (x != st [i].end () && x->first != st [bf][j].first)) {
   printf ("f{%d, %d}\n", x->first + 1, x->second);
   flag = 1;
   ans = j + 1;
   break;
   }
   */
/*
   auto x = std::lower_bound (st [j].begin (), st [j].end (), st [i][k].first, cmp);
   if (x != st [j].end () && x->first == st [i][k].first) {
   if (!flag)
   dst [i][j] = 0;
//printf ("{%d, %d}, {%d, %d}\n", st [i][k].first, st [i][k].second, x->first, x->second);
dst [i][j] += std::abs (st [i][k].second - x->second) * std::abs (st [i][k].second - x->second);
flag = 1;
}
*/
