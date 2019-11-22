#include <bits/stdc++.h>

const int N = 1e5 + 5;
int parent[N], size[N];
void init() {
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		size[i] = 1;
	}
}
int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}
bool same(int a, int b) {
	return find(a) == find(b);
}
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (size[a] < size[b]) std::swap(a, b);
	parent[b] = a;
	size[a] += size[b];
}

template <typename T> void mini(T& a, T b) {a = std::min(a, b);}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	std::vector<int> power(n+1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &power[i]);
	}

	init();

	while (m--) {
		char type;
		scanf(" %c", &type);

		if (type == '?') {
			int v;
			scanf("%d", &v);
			printf("%d\n", power[find(v)]);
		} else {
			int v, u;
			scanf("%d%d", &v, &u);
			int p1 = power[find(v)];
			int p2 = power[find(u)];
			unite(v, u);
			mini(power[find(v)], std::min(p1, p2));
		}
	}

	return 0;
}
