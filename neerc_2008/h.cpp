#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::pair <int, int> pi;

const int MAXN = 1e5 + 1;

int n;
pi arr [MAXN];
int ans [MAXN];

void input () {
	freopen ("hell.in", "r", stdin);
	freopen ("hell.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr [i].first);
		arr [i].second = i;
	}

	solve ();
}

void solve () {
	ll sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr [i].first;

	if (sum % 2) {
		puts ("No");
		return;
	}
	else {
		ll a = 0, b = 0;
		std::sort (arr, arr + n);

		for (int i = n - 1; i >= 0; i--)
			if (a <= b) {
				a += arr [i].first;
				ans [arr [i].second] = 1;
			}
			else {
				b += arr [i].first;
				ans [arr [i].second] = -1;
			}
		if (a != b) {
			puts ("No");
			return;
		}
	}

	puts ("Yes");
	for (int i = 0; i < n; i++)
		if (i + 1 < n)
			printf ("%d ", ans [i]);
		else
			printf ("%d\n", ans [i]);
}

int main () {
	input ();
	return 0;
}
