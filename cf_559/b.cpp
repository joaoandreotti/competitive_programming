#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 3e5 + 1;

int n;
int arr [MAXN];

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", arr + i);
	solve ();
}

void solve () {
	std::sort (arr, arr + n);
	int ans = INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		printf ("{%d, %d}\n", arr [i] / abs (i - (n - 1)), ans);
		ans = std::min (arr [i] / abs (i - (n - 1)), ans);
	}
	printf ("%d\n", ans);
}

int main () {
	input ();
	return 0;
}
