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
	std::stack <int> stk;
	std::vector <int> ans;
	ans.resize (n);
	for (int i = 0; i < n; i++) {
		if (str [i] == '(') {
			stk.push (str [i]);
			ans [i] = stk.size ();
		}
		else {
			ans [i] = stk.size ();
			stk.pop ();
		}
	}
	for (int i = 0; i < n; i++)
		printf ("%d", ans [i] % 2);
	puts ("");
}

int main () {
	input ();
	return 0;
}
