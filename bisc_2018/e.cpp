#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::vector <int> vi;
typedef std::set <vi> svi;

const int INF = 0x3f3f3f3f;

int n;
vi pans;
svi ans, fin;

void part (int x, int y) {
	if (!x) {
		//std::sort (pans.begin (), pans.end (), std::greater <int> ());
		//int sum = 0;
		//for (int i = 0; i < pans.size (); i++)
			//sum += pans [i];
		//if (sum == n)
		ans.insert (pans);
		return;
	}

	for (int i = 1; i <= x; i++) {
		if (i < y)
			continue;
		pans.push_back (i);
		part (x - i, i);
		pans.pop_back ();
	}
}

void input () {
	scanf ("%d", &n);
	solve ();
}

void solve () {
	part (n, 1);

	for (auto v = ans.rbegin (); v != ans.rend (); v++) {
		vi x = (*v);
		std::sort (x.begin (), x.end (), std::greater <int> ());
		fin.insert (x);
	}

	for (auto v = fin.rbegin (); v != fin.rend (); v++) {
		for (int i = 0; i < (*v).size (); i++)
			if (i + 1 < (*v).size ())
				printf ("%d+", (*v) [i]);
			else
				printf ("%d\n", (*v) [i]);
	}
}

int main () {
	input ();
	return 0;
}
