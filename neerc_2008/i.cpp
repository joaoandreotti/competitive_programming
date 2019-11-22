#include <bits/stdc++.h>

void input ();
void solve ();

std::string type, var;

void input () {
	freopen ("isharp.in", "r", stdin);
	freopen ("isharp.out", "w", stdout);
	std::cin >> type;
	while (std::cin >> var)
		solve ();
}

void solve () {
	std::cout << type;
	for (int i = var.size () - 2; i > 0; i--)
		if (var [i] == '[')
			std::cout << ']';
		else if (var [i] == ']')
			std::cout << '[';
		else if (var [i] >= 'a' && var [i] <= 'z' || var [i] >= 'A' && var [i] <= 'Z')
			break;
		else
			std::cout << var [i];

	std::cout << ' ';
	for (int i = 0; i < var.size (); i++)
		if (var [i] >= 'a' && var [i] <= 'z' || var [i] >= 'A' && var [i] <= 'Z')
			std::cout << var [i];
	std::cout << ";\n";
}

int main () {
	input ();
	return 0;
}
