#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 2;

typedef std::map <int, int> mi;

int n;
long long arr [MAXN];
mi map;

void input () {
	scanf ("%d", &n);
	memset (arr, 0x3f, sizeof arr);
	for (int i = 0; i < n; i++) {
		scanf ("%lld", arr + i);
		arr [i] = abs (arr [i]);
	}
	solve ();
}

void solve () {
	std::sort (arr, arr + n + 1);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		//printf ("%d ", arr [i]);
		if (arr [i] == 0)
			continue;
		auto x = std::upper_bound (arr, arr + n, 2 * arr [i]);
		if (*x > 2 * arr [i])
			x--;
		ans += x - (arr + i);
	}
	puts ("");
	printf ("%lld\n", ans);
}

int main () {
	input ();
	return 0;
}
