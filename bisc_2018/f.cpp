#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 50;

int n, k;
std::string dp [MAXN];

std::string fib (int n) {
	if (dp [n] != "")
		return dp [n];
	if (n == 0)
		return dp [n] = "0";
	if (n == 1)
		return dp [n] = "01";

	return dp [n] = fib (n - 1) + fib (n - 2);
}

void input () {
	scanf ("%d%d", &n, &k);
	solve ();
}

void solve () {
	std::string str = fib (k);
	std::cout << str << '\n';
}

int main () {
	input ();
	return 0;
}
