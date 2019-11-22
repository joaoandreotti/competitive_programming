#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;
typedef std::set <int> si;

const int MAXN = 3e5 + 1;

int n, m;
int arr [MAXN], brr [MAXN];
int num [MAXN];
pi ans [MAXN];
si set;

int cmp (pi a, int b) {
	return a.first < b;
}

void input () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d%d", arr + i, brr + i);
		set.insert (arr [i]);
		set.insert (brr [i]);
	}

	solve ();
}

void solve () {
	int flag = 0;

	num [arr [0]] = 1;
	for (int i = 1; i < m; i++)
		if (arr [0] == arr [i] || arr [0] == brr [i])
			num [arr [0]]++;
	for (int i = 1; i < m; i++) {
		if (arr [0] != arr [i] && arr [0] != brr [i]) {
			num [arr [i]]++;
			num [brr [i]]++;
		}
	}
	for (int i = 0; i <= n; i++)
		if (arr [0] != i && arr [0] != i) {
			//printf ("{%d, %d} {%d, %d}\n", arr [0], i, num [arr [0]], num [i]);
			if (m - num [arr [0]] == num [i]) {
				flag = 1;
			}
		}

	memset (num, 0, sizeof num);
	num [brr [0]] = 1;
	for (int i = 1; i < m; i++)
		if (brr [0] == arr [i] || brr [0] == brr [i])
			num [brr [0]]++;
	for (int i = 1; i < m; i++) {
		if (brr [0] != arr [i] && brr [0] != brr [i]) {
			num [arr [i]]++;
			num [brr [i]]++;
		}
	}
	for (int i = 0; i <= n; i++)
		if (brr [0] != i && brr [0] != i) {
			//printf ("{%d, %d} {%d, %d}\n", brr [0], i, num [brr [0]], num [i]);
			if (m - num [brr [0]] == num [i])
				flag = 1;
		}
	
	if (flag)
		puts ("YES");
	else
		puts ("NO");
}

int main () {
	input ();
	return 0;
}
