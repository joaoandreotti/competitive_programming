#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <int> vi;

const int MAXN = 1e2 + 1;

std::string str1, str2;
int dp [MAXN][MAXN];
pi t [MAXN][MAXN];
vi t1, t2;

int lcs (int i, int j) {
	if (i >= str1.size () || j >= str2.size ())
		return 0;

	if (dp [i][j])
		return dp [i][j];


	if (str1 [i] == str2 [j]) {
		dp [i][j] = lcs (i + 1, j + 1) + 1;
		t [i][j] = std::make_pair (i + 1, j + 1);
	}
	else {
		int a = lcs (i + 1, j), b = lcs (i, j + 1);

		if (a > b) {
			dp [i][j] = a;
			t [i][j] = std::make_pair (i + 1, j);
		}
		else {
			dp [i][j] = b;
			t [i][j] = std::make_pair (i, j + 1);
		}
	}

	return dp [i][j];
}

void input () {
	std::cin >> str1 >> str2;
	solve ();
}

void solve () {
	printf ("%d\n", lcs (0, 0));

	int a = 0, b = 0;
	while (a < str1.size () && b < str2.size ()) {
		//printf ("{%d, %d} = {%c, %c}\n", a, b, str1 [a], str2 [b]);
		if (str1 [a] == str2 [b]) {
			t1.push_back (t [a][b].first);
			t2.push_back (t [a][b].second);
		}

		pi p = t [a][b];
		a = p.first;
		b = p.second;
	}

	for (int i = 0; i < t1.size (); i++)
		printf ("%d ", t1 [i]);
	puts ("");
	for (int i = 0; i < t2.size (); i++)
		printf ("%d ", t2 [i]);
	puts ("");
}

int main () {
	input ();
	return 0;
}
