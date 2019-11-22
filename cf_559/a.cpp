#include <bits/stdc++.h>

void input ();
void solve ();

int n;
std::string str;

void input () {
	scanf ("%d", &n);
	std::cin >> str;
	solve ();
}

void solve () {
	int i;
	for (i = 0; i < n; i++)
		if (str [i] != '-')
			break;
	int ans = 0;
	for (; i < n; i++)
		if (str [i] == '+')
			ans++;
		else if (ans)
			ans--;
	printf ("%d\n", ans);
}

int main () {
	input ();
	return 0;
}
