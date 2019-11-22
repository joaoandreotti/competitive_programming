#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5;

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

int n;
int arr [MAXN];
int vis [MAXN];
vvi perm, ans;

bool check (vi a, vi b) {
	int dif = 0;
	vi c;
	for (int i = 0; i < a.size (); i++) {
		if (a [i] != b [i]) {
			dif++;
			c.push_back (i);
		}
			
	}

	return dif == 2 && abs (c [0] - c [1]) == 1;
}

void bt (vi x) {
	if (ans.size () == perm.size ()) {
		for (int i = 0; i < ans.size (); i++) {
			for (int j = 0; j < ans [i].size (); j++)
				printf ("%d ", ans [i][j]);
			puts ("");
		}
		exit (0);
	}

	for (int i = 0; i < perm.size (); i++) {
		if (!vis [i] && check (x, perm [i])) {
			ans.push_back (perm [i]);
			vis [i] = 1;
			bt (perm [i]);
			vis [i] = 0;
			ans.pop_back ();
		}
	}
}

void input () {
	scanf ("%d", &n);
	solve ();
}

void solve () {
	for (int i = 1; i <= n; i++)
		arr [i - 1] = i;

	do {
		vi a;
		perm.push_back (a);
		for (int i = 0; i < n; i++) {
			perm [perm.size () - 1].push_back (arr [i]);
			printf ("%d ", arr [i]);
		}
		puts ("");
	} while (std::next_permutation (arr, arr + n));

	/*
	for (int i = 0; i < perm.size (); i++) {
		ans.push_back (perm [i]);
		vis [i] = 1;
		bt (perm [i]);
		vis [i] = 0;
		ans.pop_back ();
	}
	*/
}

int main () {
	input ();
	return 0;
}
