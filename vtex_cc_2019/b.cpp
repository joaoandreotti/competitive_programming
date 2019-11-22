#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::pair <int, pi> ppi;
typedef std::vector <ppi> vppi;

int n, arr [3];
vppi v;

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d%d", arr, arr + 1, arr + 2);
		std::sort (arr, arr + 3);
		v.push_back ({arr [0], {arr [1], arr [2]}});
	}
	solve ();
}

void solve () {
	std::sort (v.begin (), v.end ());
	//for (ppi x : v) {
		//printf ("{%d, %d, %d}\n", x.first, x.second.first, x.second.second);
	//}
	int flag = 1;
	for (int i = 0; i < (n - 1); i++) {
		if (v [i].first >= v [i + 1].first)
			flag = 0;
		if (v [i].second.first >= v [i + 1].second.first)
			flag = 0;
		if (v [i].second.second >= v [i + 1].second.second)
			flag = 0;
	}
	if (flag)
		puts ("S");
	else
		puts ("N");
}

int main () {
	input ();
	return 0;
}
