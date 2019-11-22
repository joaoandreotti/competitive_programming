#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e6;

int n, m, ab, bc, k;
int arr [MAXN], arr1 [MAXN], brr [MAXN];

void input () {
	scanf ("%d%d%d%d%d", &n, &m, &ab, &bc, &k);
	for (int i = 0; i < n; i++)
		scanf ("%d", arr + i);
	for (int i = 0; i < m; i++)
		scanf ("%d", brr + i);
	solve ();
}

void solve () {
	for (int i = 0; i < n; i++)
		arr1 [i] = *std::lower_bound (brr, brr + m, arr [i] + ab);

	/*
	puts ("---");
	for (int i = 0; i < n; i++)
		printf ("%d ", arr1 [i]);
	puts ("");
	*/

	if (k >= std::min (n, m)) {
		puts ("-1");
		return;
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int p = k - i;
		// earlier arr1 [p]
		int *j = std::lower_bound (brr, brr + m, arr1 [i]);
		//printf ("(%d, %d}\n", i, j - brr);
		if ((j - brr) + p >= m || (j - brr) == m || !arr1 [i]) {
			ans = -1;
			break;
		}
		ans = std::max (brr [(j - brr) + p] + bc, ans);
	}
	printf ("%d\n", ans);
}

int main () {
	input ();
	return 0;
}
