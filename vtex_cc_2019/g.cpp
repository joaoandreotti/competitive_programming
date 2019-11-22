#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::pair <long long, long long> pi;
typedef std::pair <pi, long long> ppi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;
typedef std::vector <ppi> vppi;
typedef std::priority_queue <ppi> pqpi;

long long n, k;
vppi arr;
vvpi ans;
pqpi pq;

void input () {
	scanf ("%lld%lld", &n, &k);
	ans.resize (2);
	for (long long i = 0; i < n; i++) {
		long long a, b; scanf ("%lld%lld", &a, &b);
		arr.push_back ({{a, i}, b});
	}
	solve ();
}

void solve () {
	std::sort (arr.begin (), arr.end ());
	pq.push ({{-(arr [0].first.first + arr [0].second), arr [0].first.second}, 0});

	int qa = 1, qb = 0;
	int lqa = 0, lqb = 0;
	int client = 1;
	while (!pq.empty () && client < n) {
		ppi top = pq.top (); pq.pop ();
		top.first.first = -top.first.first;
		ans [top.second].push_back ({top.first.second, top.first.first});
		ppi next = arr [client++];

		if (top.second == 0)
			lqa += top.first.first;
		else
			lqb += top.first.first;

		if (qa <= qb || ((qa - 1) == qb && next.first.first >= top.first.first)) {
			qa++;
			if (((qa - 1) == qb && next.first.first >= top.first.first))
				qa--;
			pq.push ({{-(lqa + ((next.second))), next.first.second}, 0});
		}
		else {
			qb++;
			pq.push ({{-(lqb + ((next.second * k) + next.first.first)), next.first.second}, 1});
		}
	}

	puts ("A");
	for (int i = 0; i < ans [0].size (); i++)
		printf ("{%d, %d}\n", ans [0][i].first, ans [0][i].second);
	puts ("B");
	for (int i = 0; i < ans [1].size (); i++)
		printf ("{%d, %d}\n", ans [1][i].first, ans [1][i].second);
}

int main () {
	input ();
	return 0;
}
