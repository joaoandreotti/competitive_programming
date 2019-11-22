#include <bits/stdc++.h>

void input ();
void solve ();

const int n = 3;
int arr [n];

void input () {
	for (int i = 0; i < n; i++)
		scanf ("%d", arr + i);
	solve ();
}

void solve () {
	int flag = 0;
	if (arr [0] != arr [1] && arr [0] != arr [2])
		flag = 1;
	if (arr [1] != arr [0] && arr [1] != arr [2])
		flag = 2;
	if (arr [2] != arr [0] && arr [2] != arr [1])
		flag = 3;

	if (flag == 1)
		puts ("A");
	else if (flag == 2)
		puts ("B");
	else if (flag == 3)
		puts ("C");
	else
		puts ("*");
}

int main () {
	input ();
}
