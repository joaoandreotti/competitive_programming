#include <bits/stdc++.h>

void solve ();
void input ();

typedef long long ll;

const int MAXN = 8*45;

int n, k;
int arr [5] = {1, 2, 1, 2, 2};
int ones [MAXN], zeroes [MAXN];
int dp [MAXN];

int fib (int n) {
	if (dp [n])
		return dp [n];

	if (n == 0)
		return dp [n] = 1;
	if (n == 1)
		return dp [n] = 1;
	return dp [n] = fib (n - 1) + fib (n - 2);
}

void input () {
	scanf ("%d%d", &k, &n);
	solve ();
}

void solve () {
	fib (44);
	int count = 0;
	for (int i = 0; i < (1LL << n); i++) {
		int flag = 0;
		for (int j = n; j >= 0; j--)
			if ((i >> j) & 1 && (i >> (j + 1)) & 1)
				flag = 1;
		if (flag)
			continue;
		count++;
		printf ("%3d --- ", count);
		for (int j = n - 1; j >= 0; j--)
			if ((i >> j) & 1)
				printf ("1");
			else
				printf ("\x1b[34m" "0" "\x1b[0m");
		printf (" --- %d\n", i);

	}
}

int main () {
	input ();
	return 0;
}
