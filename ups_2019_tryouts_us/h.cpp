#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;

const int MAXN = 1e2 + 1;
const ll INF = LONG_MAX;

ll n, m;
//vvpi g;
ll g [MAXN][MAXN];


void input () {
	scanf ("%lld%lld", &n, &m);
	memset (g, -1, sizeof g);
	for (ll i = 0, a; i < n; i++) {
		scanf ("%lld", &a);
		for (ll j = 0, b, c; j < a; j++) {
			scanf ("%lld%lld", &b, &c);
			b--;
			g [i][b] = c;
		}
	}
	solve ();
}

void solve () {
	for (int i = 0; i < n; i++) {
		ll dst = INF, idx = -1;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				ll crr = 0;
				int flag = 0;
				for (ll k = 0; k < m; k++)
					if (g [i][k] != -1 && g [j][k] != -1) {
						flag = 1;
						crr += (g [i][k] - g [j][k]) * (g [i][k] - g [j][k]);
					}
				if (flag && crr < dst) {
					dst = crr;
					idx = j;
				}
			}
		}
		ll max = -1, idy = -1;
		for (ll j = 0; j < m; j++) {
			if (g [i][j] == -1 && g [idx][j] != -1) {
				if (g [idx][j] > max) {
					max = g [idx][j];
					idy = j;
				}
			}
		}
		if (idy != -1)
			printf ("%lld\n", idy + 1);
		else
			printf ("%lld\n", idy);
	}
}

int main () {
	input ();
	return 0;
}
