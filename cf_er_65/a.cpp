#include <bits/stdc++.h>

void input ();
void solve ();

int t, n;
std::string str;

void input () {
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d", &n);
		std::cin >> str;
		solve ();
	}
}

void solve () {
	int pos = INT_MAX;
	for (int i = 0; i < n; i++)
		if (str [i] == '8') {
			pos = i;
			break;
		}
	if (n - pos >= 11)
		puts ("YES");
	else
		puts ("NO");
}

int main () {
	input ();
	return 0;
}
