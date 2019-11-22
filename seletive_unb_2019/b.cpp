#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

int n, m, min, max, mid;
std::vector <int> arr;

int check (int x) {
	int cont = 0;
	if (x == 0)
		return 0;
	for (int i = n - 1; i >= 0; i--) {
		cont += arr [i] / x;
		if (cont >= m)
			return 1;
	}
	return 0;
}

void input () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a; scanf ("%d", &a);
		arr.push_back (a);
		min = std::min (arr [i], min);
		max = std::max (arr [i], max);
	}
	solve ();
}

void solve () {
	std::sort (arr.begin (), arr.end ());
	mid = (min + max) / 2;
	int ans = 0;
	//printf ("%d\n", check (2, arr));
	for (int i = 0; i < 32; i++) { // 50 max iters
		if (check (mid)) {
			ans = mid;
			min = mid + 1;
			mid = (min + max) / 2;
		}
		else {
			max = mid;
			mid = (min + max) / 2;
		}
	}
	printf ("%d\n", ans);
}

int main () {
	input ();
	return 0;
}
