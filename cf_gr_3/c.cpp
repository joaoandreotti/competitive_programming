#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e6;

typedef std::pair <int, int> pi;
typedef std::set <pi> spi;

int n;
int arr [MAXN], rev [MAXN];
spi ans;


void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", arr + i);
		arr [i]--;
		rev [arr [i]] = i;
	}
	solve ();
}

void solve () {
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < n; i++) {
			if (arr [i] != i) {
				if (2 * abs (arr [i] - i) >= n) {
					ans.insert ({i, arr [i]});
					std::swap (arr [i], arr [rev [i]]);
				}
				if (arr [i] - 1 >= n/2) {
					ans.insert ({1, arr [i]});
					std::swap (arr [i], arr [rev [i]]);
				}
			}
		}
		puts ("---");
		for (int i = 0; i < n; i++)
			printf ("%d ", arr [i]);
		puts ("\n---");
	}

	printf ("%d\n", ans.size ());
	for (auto i = ans.begin (); i != ans.end (); i++)
		printf ("%d %d\n", i->first + 1, i->second + 1);
	puts ("");
}

int main () {
	input ();
	return 0;
}
