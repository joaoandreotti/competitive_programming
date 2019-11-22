#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <char> vc;
typedef std::vector <vc> vvc;

char p [2] = {'(', ')'};

int n;
vc tmp;
vvc ans;

void bt (int r) {
	if (!r) {
		int l = 0, flag = 0;
		for (int i = 0; i < tmp.size (); i++) {
			if (tmp [i] == '(')
				l++;
			else
				l--;
			if (l < 0)
				flag = 1;
		}
		if (!flag && !l)
			ans.push_back (tmp);
		return;
	}

	for (int i = 0; i < 2; i++) {
		tmp.push_back (p [i]);
		bt (r - 1);
		tmp.pop_back ();
	}
}

void input () {
	scanf ("%d", &n);
	n *= 2;
	solve ();
}

void solve () {
	bt (n);
	std::sort (ans.begin (), ans.end ());
	for (int i = 0; i < ans.size (); i++) {
		for (int j = 0; j < ans [i].size (); j++)
			printf ("%c", ans [i][j]);
		puts ("");
	}
}

int main () {
	input ();
	return 0;
}
