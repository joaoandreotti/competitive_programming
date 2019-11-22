#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef std::vector <ll> vl;

ll a, b;
vl dv;


void input () {
  scanf ("%lld%lld", &a, &b);
  solve ();
}

void solve () {
  // O (1e6)
  for (ll i = 1; (i*i) <= a; i++)
    if (a % i == 0) {
      dv.push_back (i);
      if (i != (a / i))
        dv.push_back (a / i);
    }

  std::sort (dv.begin (), dv.end ());

  for (int i = 0; i < dv.size (); i++)
    if (dv [i] % b == 0)
      printf ("%lld ", dv [i]);

  puts ("");

}

int main () {
  input ();
  return 0;
}
