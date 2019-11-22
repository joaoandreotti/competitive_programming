#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXT = 4e4 + 1;

int n, m;
std::vector <std::pair <int, int> > arr;
int in [MAXT], out [MAXT];

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf ("%d%d", &a, &b);
		arr.push_back ({a, b});
		in [a]++;
		out [b]++;
		m = std::max (m, b);
	}
	solve ();
}

void solve () {
	std::sort (arr.begin (), arr.end ());
	int b = 0, e = 0;
	int ans = 0, crr = 0, max = 1;
	for (int i = 0; i <= m; i++) {
		crr += in [i];
		crr -= out [i];
		if (!in [i] && crr)
			max++;
		else {
			ans = std::max (ans, max);
			max = 1;
		}
		//printf ("{%d, %d, %d}\n", crr, max, ans);
	}
	ans = std::max (ans, max);
	printf ("%d\n", ans);
}

int main () {
	input ();
	return 0;
}
