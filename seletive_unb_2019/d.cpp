#include <bits/stdc++.h>

void input ();
void solve ();

int a, b, c, d, e;

void input () {
	scanf ("%d", &e);
	solve ();
}

void solve () {
	b = -1;
	d = 1;
	int flag = 0;
	for (a = -1000; a <= 1000; a++) {
		for (c = -1000; c <= 1000; c++) {
			if (a != 0 && c != 0 && a + c == e && a != b && a != c && a != d && b != c && b != d && c != d) {
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	printf ("%d %d\n%d %d\n", a, b, c, d);
}

int main () {
	input ();
	return 0;
}
