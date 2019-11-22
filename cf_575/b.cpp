#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

typedef long long ll;
typedef std::vector <int> vi;

int n, q, k;
ll arr [MAXN * 2];
vi ans;

void input () {
	scanf ("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf ("%d%d", &n, &k);
		for (int j = 0; j < n; j++)
			scanf ("%lld", arr + j);
		ans.clear ();
		solve ();
	}
}

void solve () {
	long long sum = 0;
	int l = 0;

	for (int i = 0; i < n; i++) {
		sum += arr [i];
		if (sum % 2) {
			ans.push_back (i + 1);
			sum = 0;
		}
		if (ans.size () == k || i + 1 >= n) {
			l = i;
			break;
		}
	}

	//printf ("l: %d\n", l);
	if (l != (n - 1)) {
		for (int i = ans [ans.size () - 1]; i < n; i++)
			sum += arr [i];
		//printf ("sum: %lld\n", sum);
		if (sum % 2 == 0) {
			puts ("NO");
			return;
		}
		ans.push_back (n);
	}

	if (ans.size () != k) {
		puts ("NO");
		return;
	}


	puts ("YES");
	for (int i = 0; i < ans.size (); i++)
		printf ("%d ", ans [i]);
	puts ("");
}

int main () {
	input ();
	return 0;
}
