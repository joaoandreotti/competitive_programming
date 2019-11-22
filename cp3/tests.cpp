#include <bits/stdc++.h>

void input ();
void solve ();

void input () {
	int a;
	std::string str;
	while (getline (std::cin, str)) {
		printf ("{%d, %d}\n", a, str.size ());
	}
}

int main () {
	input ();
	return 0;
}
