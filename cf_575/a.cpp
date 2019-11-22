#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;

ll n, arr [3];

void input () {
	scanf ("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%lld%lld%lld", arr, arr + 1, arr + 2);
		solve ();
	}
}

void solve () {
	std::sort (arr, arr + 3);
	//for (int i = 0; i < 3; i++)
		//printf ("%lld\n", arr [i]);
	arr [2] -= arr [1] - arr [0];
	arr [0] += arr [1] - arr [0];
	printf ("%lld\n", arr [0] + (arr [2] / 2));
}

int main () {
	input ();
	return 0;
}
