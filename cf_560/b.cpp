#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

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
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (arr [i] >= ans)
			ans++;
	}
	printf ("%d\n", ans - 1);
}

int main () {
	input ();
	return 0;
}
