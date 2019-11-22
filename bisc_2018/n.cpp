#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <int, char> pc;
typedef std::pair <int, pc> pipc;
typedef std::vector <pipc> vpipc;

int n, a;
vpipc arr;

bool cmp (pipc a, pipc b) {
	return a.second.first < b.second.first;
}

void input () {
	scanf ("%d%d", &n, &a);
	for (int i = 0; i < n; i++) {
		int b; scanf ("%d", &b);
		arr.push_back ({b, {i, '!'}});
	}
	solve ();
}

void solve () {
	std::sort (arr.begin (), arr.end (), std::greater <pipc> ());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		//printf ("sum: %d\n", sum);
		if (arr [i].second.first == 0)
			sum += arr [i].first;
		else {
			//printf ("%d => s1: %d | s2: %d\n", arr [i].first, (arr [i].first + sum), (arr [i].first - sum));
			if (abs ((arr [i].first + sum) - a) < abs ((sum - arr [i].first) - a)) {
				sum += arr [i].first;
				arr [i].second.second = '+';
			}
			else {
				sum -= arr [i].first;
				arr [i].second.second = '-';
			}
		}
	}

	std::sort (arr.begin (), arr.end (), cmp);

	printf ("%d\n", sum);
	for (int i = 0; i < n; i++)
		if (i)
			printf ("%c%d", arr [i].second.second, arr [i].first);
		else
			printf ("%d", arr [i].first);
	puts ("");
}

int main () {
	input ();
	return 0;
}
