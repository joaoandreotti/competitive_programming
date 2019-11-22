#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::vector <ll> vl;

const int MAXN = 1e7;

int n;
vl isp (MAXN, true), p, spf (MAXN);

void sieve () {
  isp [0] = false;
  isp [1] = false;

  for (int i = 2; i <= MAXN; i++) {
    if (isp [i]) {
      p.push_back (i);
      spf [i] = i;
    }

    for (long long j = 0; (j < p.size ()) && (i * p [j] < MAXN) && (p [j] <= spf [i]); j++) {
      isp [i * p [j]] = false;
      spf [i * p [j]] = p [j];
    }
  }
}

void input () {
	scanf ("%d", &n);
	solve ();
}

void solve () {
	sieve ();
	printf ("%lld\n", p [n - 1]);
}

int main () {
	input ();
	return 0;
}
