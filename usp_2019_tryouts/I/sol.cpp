#include <bits/stdc++.h>

template <typename T> void maxi(T& a, T b) {a = std::max(a, b);}
const long long NINF = 0xc0c0c0c0c0c0c0c0;

int main() {
	int n;
	scanf("%d", &n);

	std::vector<std::pair<int, int> > a(n + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].second, &a[i].first);
	}

	std::sort(a.begin() + 1, a.end());

	std::vector<long long> prefixSum(n + 1); 

	long long ans = NINF;
	for (int i = 1; i <= n; i++) {
		prefixSum[i] = prefixSum[i-1] + a[i].second;
		maxi(ans, prefixSum[i] - a[i].first);
	}

	printf("%lld\n", ans);
	return 0;
}
