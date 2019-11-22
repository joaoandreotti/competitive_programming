#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::map <char, int> mci;

int n;
mci map, r1, r2;

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		map [str [0]]++;
	}
	solve ();
}

void solve () {
	for (auto x : map) {
		r1 [x.first] = x.second / 2;
		r2 [x.first] = x.second - r1 [x.first];
	}
	int ans = 0;
	for (auto x : r1)
		ans += ((x.second * x.second) - (x.second)) / 2;
	for (auto x : r2)
		ans += ((x.second * x.second) - (x.second)) / 2;
	printf ("%d\n", ans);
}

int main () {
	input ();
	return 0;
}
