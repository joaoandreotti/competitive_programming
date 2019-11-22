#include <bits/stdc++.h>

void input ();
void solve ();

int m, d;

void input () {
	scanf ("%d%d", &m, &d);
	solve ();
}

void solve () {
	int c = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 11; j <= d; j++)
			if ((j % 10) > 1 && (j / 10) > 1 && ((j % 10) * (j / 10)) == i)
				c++;
	printf ("%d\n", c);
}

int main () {
	input ();
	return 0;
}
