#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;

int n, q, v;
vpi arr;

void input () {
	scanf ("%d%d%d", &n, &q, &v);
	arr.clear ();
	for (int i = 0; i < q; i++) {
		int a, b, c; scanf ("%d%d%d", &a, &b, &c);
		if (c > v) // ultrapassou o limite
			arr.push_back ({a, b});
	}
	solve ();
}

void solve () {
	std::sort (arr.begin (), arr.end ());
	if (arr.empty ()) {
		puts ("-1");
		return;
	}
	int min = arr [0].first, max = arr [0].second;
	int ans = max - min;
	for (int i = 1; i < arr.size (); i++) {
		if (min < arr [i].first)
			min = arr [i].first;
		if (max < arr [i].second)
			max = arr [i].second;
		ans = std::min (max - min, ans);
		//printf ("{%d, %d} | {%d, %d}\n", min, max, arr [i].first, arr [i].second);
	}
	printf ("%d\n", ans + 1);
}

int main () {
	input ();
	return 0;
}
