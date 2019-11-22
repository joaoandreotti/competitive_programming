#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::map <char, int> mci;

int n;
char arr [5] = {'a', 'e', 'i', 'o', 'u'};
mci map;

void input () {
	scanf ("%d", &n);
	solve ();
}

void solve () {
	int div = 0;
	for (int i = 2; (i*i) <= n; i++) {
		if (n % i == 0)
			div = std::max (n / i, i);
		if (div >= 5 && n / div >= 5)
			break;
	}

	if (div < 5 || n / div < 5)
		puts ("-1");
	else {
		map ['a'] = 0;
		map ['e'] = 1;
		map ['i'] = 2;
		map ['o'] = 3;
		map ['u'] = 4;
		std::string str;
		for (int j = 0; j < div; j++)
			str += arr [j % 5];
		std::cout << str;
		for (int i = 1; i < (n / div); i++) {
			std::string a;
			for (int j = 0; j < div; j++)
				a += arr [(map [str [j]] + 1) % 5];
			std::cout << a;
			str = a;
		}
		puts ("");
	}
}

int main () {
	input ();
	return 0;
}
