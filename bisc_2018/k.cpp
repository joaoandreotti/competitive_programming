#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int MAXN = 1e5;

int n, k;
int arr [MAXN];
int vis [MAXN];
vi crr;
vvi pc, ans;

bool cmp (vi a, vi b) {
	vi x1, x2;
	for (int i = 1; i < a.size (); i++)
		x1.push_back (a [i]);
	for (int i = 1; i < b.size (); i++)
		x2.push_back (b [i]);
	if (x1 < x2)
		return true;
	return false;
}

bool check (vi a, vi b) {
	int dif = 0;
	std::sort (a.begin (), a.end ());
	std::sort (b.begin (), b.end ());
	for (int i = 0; i < a.size (); i++) {
		int flag = 0;
		for (int j = 0; j < b.size (); j++)
			if (a [i] == b [j])
				flag = 1;
		if (!flag)
			dif++;
			
	}

	return dif <= 1;
}

void bt (vi x) {
	//printf ("%d\n", (int) ans.size ());
	if (ans.size () == pc.size ()) {
		for (int i = 0; i < ans.size (); i++) {
			for (int j = 0; j < ans [i].size (); j++)
				printf ("%d ", ans [i][j]);
			puts ("");
		}
		exit (0);
	}

	for (int i = 0; i < pc.size (); i++)
		if (!vis [i] && check (x, pc [i])) {
			ans.push_back (pc [i]);
			vis [i] = 1;
			bt (pc [i]);
			vis [i] = 0;
			ans.pop_back ();
		}
}

void cmb (int k, int min) {
	if (!k)
		pc.push_back (crr);
	else
		for (int i = min; i <= n; i++) {
			crr.push_back (i);
			cmb (k - 1, i + 1);
			crr.pop_back ();
		}
}


void input () {
	scanf ("%d%d", &n, &k);
	solve ();
}

void solve () {
	cmb (k, 1);
	for (int i = 0; i < pc.size (); i++) {
		ans.push_back (pc [i]);
		vis [i] = 1;
		bt (pc [i]);
		vis [i] = 0;
		ans.pop_back ();
	}

	printf ("%d\n", (int) ans.size ());
	for (int i = 0; i < ans.size (); i++) {
		for (int j = 0; j < ans [i].size (); j++)
			printf ("%d ", ans [i][j]);
		puts ("");
	}
}

int main () {
	input ();
	return 0;
}
