#include <bits/stdc++.h>

const int MAXN = 3e2 + 1;

int arr [MAXN * MAXN];

int rand(int a, int b) {
	return rand() % (b - a + 1) + a;
}

int32_t main(int argc, char* argv[]) {
	srand(atoi(argv[1]));

	int n, m;
	n = rand() % 301;
	m = rand() % 301;
	if (!n)
		n++;
	if (!m)
		m++;
	printf("%d %d\n", n, m);

	std::iota (arr, arr + (n * m), 1);
	std::random_shuffle (arr, arr + (n * m));
	int cont = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf ("%d ", arr [cont++]);
		puts ("");
	}

	return 0;
}
