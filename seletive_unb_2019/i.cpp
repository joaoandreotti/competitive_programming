#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

int n, p;
int dp [MAXN];


// pascal triangle and binomial coefficient
// (n k) = n! / (k!(n - k)!)
// so N will be N
// and K will be N/2
// this function counts how many primes P
// divides the factorial of X
// and stores in dp [X]
// THIS ONLY WORKS because P is a Prime, ans if it
// divides a number X it means that it is inside X
// prime factoration
int f (int x) {
	if (dp [x] != -1)
		return dp [x];
	if (x == 0)
		return dp [x] = 0;

	dp [x] = f (x - 1);
	int aux = x;
	while (!(aux % p)) {
		aux /= p;
		dp [x]++;
	}
	/*
	if (!(x % p))
		dp [x] += x / p;
		*/
	return dp [x];
}

void input () {
	scanf ("%d%d", &n, &p);
	solve ();
}

void solve () {
	memset (dp, -1, sizeof dp);
	f (n);
	long long cnt = 0;
	for (int i = 0; i <= n; i++) {
		//printf ("dp [%d]: %d\n", i, dp [i]);
		if (dp [i] > (dp [i / 2] + dp [(i + 1) / 2]))
			cnt++;
	}
	printf ("%lld\n", cnt);
}

int main () {
	input ();
	return 0;
}
