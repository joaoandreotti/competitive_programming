#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 3e5 + 1;

int n, m;
int arr [MAXN];

void input () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf ("%d", arr + i);
	solve ();
}

void solve () {
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr [i] > arr [i + 1])
			ans += m - arr [i];
		if (i && (m - arr [i] < arr [i - 1]
}

int main () {
	return 0;
}
