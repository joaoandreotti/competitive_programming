#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, int> pi;

int cnt = 0;
int arr [6] = {4, 8, 15, 16, 23, 42};
int ans [6];
int q [4];
pi pdt [1765];

void input () {
	solve ();
	printf ("? %d %d\n", 1, 1);
	fflush (stdout);
	scanf ("%d", q + cnt++);
	ans [cnt - 1] = pdt [q [cnt - 1]].first;

	printf ("? %d %d\n", 2, 2);
	fflush (stdout);
	scanf ("%d", q + cnt++);
	ans [cnt - 1] = pdt [q [cnt - 1]].first;

	printf ("? %d %d\n", 3, 4);
	fflush (stdout);
	scanf ("%d", q + cnt++);
	ans [cnt - 1] = pdt [q [cnt - 1]].first;
	ans [cnt++] = pdt [q [cnt - 1]].second;

	printf ("? %d %d\n", 5, 6);
	fflush (stdout);
	scanf ("%d", q + cnt++);
	ans [cnt - 1] = pdt [q [cnt - 1]].first;
	ans [cnt++] = pdt [q [cnt - 1]].second;

	printf ("!");
	for (int i = 0; i < cnt; i++)
		printf (" %d", ans [i]);
	puts ("");
}

void solve () {
	for (int i = 0; i < 6; i++)
		for (int j = i; j < 6; j++) {
			//printf ("{%d, %d} = %d\n", arr [i], arr [j], arr [i] * arr [j]);
			pdt [arr [i] * arr [j]] = {arr [i], arr [j]};
		}
}

int main () {
	input ();
	return 0;
}
