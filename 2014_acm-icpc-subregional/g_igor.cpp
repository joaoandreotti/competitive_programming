#include <bits/stdc++.h>

#define int long long

/*
   const int MAX = 305*305;
   int bit[MAX];

   int query(int i) {
   int sum = 0;
   for (; i > 0; i -= i&-i)
   sum += bit[i];
   return sum;
   }
   void update(int i, int val) {
   for (; i < MAX; i += i&-i)
   bit[i] += val;
   }*/
int count_inv(std::vector<int> a) {
	int len = a.size();
	int inv = 0;

	for (int i = 0; i < len; i++) { //put i on the right place
		int whereis;
		for (whereis = 0; whereis < len; whereis++) {
			if (a[whereis] == i)
				break;
		}

		if (whereis == i) //its free
			continue;

		inv++;
		std::swap(a[whereis], a[i]);
	}

	return inv;
}

const int N = 305, M = 305;
int grid[N][M];

int32_t main() {
	int n, m;
	scanf("%lld%lld", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lld", &grid[i][j]);
			grid[i][j]--;
		}
	}

	std::vector<int> check_line(n);
	for (int i = 0; i < n; i++) {
		int div = grid[i][0] / m;
		for (int j = 0; j < m; j++) {
			if (grid[i][j] / m != div) {
				return puts("*"), 0;
			}
		}
		check_line[i] = div;
	}

	std::vector<int> check_column(m);
	for (int j = 0; j < m; j++) {
		int mod = grid[0][j] % m;
		for (int i = 0; i < n; i++) {
			if (grid[i][j] % m != mod) {
				return puts("*"), 0;
			}
		}
		check_column[j] = mod;
	}

	int a = count_inv(check_line);
	int b = count_inv(check_column);

	/*
	   fprintf(stderr, "\n");
	   for (int elem : check_line)
	   fprintf(stderr, "%lld ", elem);
	   fprintf(stderr, "\ncheck_line:%lld\n", a);

	   for (int elem : check_column)
	   fprintf(stderr, "%lld ", elem);
	   fprintf(stderr, "\ncheck_column:%lld\n", b);
	   */

	printf("%lld\n", a + b);
	return 0;
}
