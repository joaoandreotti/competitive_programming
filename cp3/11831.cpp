#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e4 + 10;

int n, m, s, x, y;
char arr [MAXN][MAXN];
char ori;
std::string str;

void input () {
	while (scanf ("%d%d%d", &n, &m, &s) && n) {
		memset (arr, 0, sizeof arr);
		str.clear ();
		for (int i = 0; i < n; i++) {
			std::cin >> str;
			for (int j = 0; j < m; j++) {
				arr [i][j] = str [j];
				if (arr [i][j] >= 'A' && arr [i][j] <= 'Z') {
					x = i;
					y = j;
					ori = arr [i][j];
					arr [i][j] = '.';
				}
			}
		}
		std::cin >> str;
		solve ();
	}
}

void solve () {
	int ans = 0;
	for (int i = 0; i < s; i++) {
		if (str [i] == 'F') {
			if (ori == 'N')
				if (x - 1 >= 0 && arr [x - 1][y] != '#')
					x--;
			if (ori == 'S')
				if (x + 1 < n && arr [x + 1][y] != '#')
					x++;
			if (ori == 'O')
				if (y - 1 >= 0 && arr [x][y - 1] != '#')
					y--;
			if (ori == 'L')
				if (y + 1 < m && arr [x][y + 1] != '#')
					y++;
		}
		if (str [i] == 'D') {
			if (ori == 'N')
				ori = 'L';
			else if (ori == 'S')
				ori = 'O';
			else if (ori == 'L')
				ori = 'S';
			else if (ori == 'O')
				ori = 'N';
		}
		if (str [i] == 'E') {
			if (ori == 'N')
				ori = 'O';
			else if (ori == 'S')
				ori = 'L';
			else if (ori == 'L')
				ori = 'N';
			else if (ori == 'O')
				ori = 'S';
		}
		if (arr [x][y] == '*') {
			ans++;
			arr [x][y] = '.';
		}
		//printf ("%c : {%d, %d} => %c | %c\n", str [i], x, y, arr [x][y], ori);
	}
	printf ("%d\n", ans);
}

int main () {
	input ();
	return 0;
}
