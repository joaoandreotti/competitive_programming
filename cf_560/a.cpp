#include <bits/stdc++.h>

void input ();
void solve ();

int n, x, y;
std::string str;

void input () {
	scanf ("%d%d%d", &n, &x, &y);
	std::cin >> str;
	solve ();
}

void solve () {
	int pos = 0;
	for (int i = x - 1; i >= 0; i--)
		if (str [i] == '1') {
			pos = i;
			break;
		}
	std::string a;
	for (int i = x - 1; i > y; i--)
		a += "0";
	a += "1";
	for (int i = 0; i < y; i++)
		a += "0";

	int ans = 0;
	//printf ("%s | %s\n", str.substr (n - x, x).c_str (), a.c_str ());
	for (int i = 0; i < x; i++) {
		if (a [i] != str.substr (n - x, x) [i])
			ans++;
	}
	printf ("%d\n", ans);
}

int main () {
	input ();
	return 0;
}
