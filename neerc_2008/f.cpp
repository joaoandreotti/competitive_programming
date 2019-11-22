#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXF = 6e1 + 1;;

typedef long long ll;
typedef std::vector <ll> vll;

vll fib, ans;

void input () {
	solve ();
}

void solve () {
	ll a = 1, b = 1;
	fib.push_back (a);
	for (int i = 0; i < MAXF; i++) {
		ll aux = b;
		b += a;
		a = aux;
		fib.push_back (a);
	}

	ll sum = 0;
	for (ll n = 1; n < 1e2 + 44; n++) {
		int flag = 0;
		ll aux = n;
		for (int i = fib.size () - 1; i > 0; i--)
			if (aux >= fib [i]) {
				ans.push_back (1);
				aux -= fib [i];
				flag = 1;
			}
			else if (flag)
				ans.push_back (0);
		sum += ans.size ();
		printf ("%4lld => ", sum);
		for (int i = 0; i < ans.size (); i++)
			printf ("%lld", ans [i]);
		puts("");
		ans.clear ();
	}
	printf ("sum: %lld\n", sum);
}

int main () {
	input ();
	return 0;
}
