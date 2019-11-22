#include <bits/stdc++.h>

int n, m;
int arrn [2], arrm [2];

void input ();
void solve ();

void input () {
	scanf ("%d%d", &n, &m);
	int a;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a);
		arrn [a % 2]++;
	}
	for (int i = 0; i < m; i++) {
		scanf ("%d", &a);
		arrm [a % 2]++;
	}
}

void solve () {
	printf ("%d", std::min (arrn [0], arrm [1]) + std::min (arrn [1], arrm [0]));
}

int main () {
	input ();
	solve ();
	return 0;
}
