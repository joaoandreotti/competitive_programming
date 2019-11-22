#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e7;

std::set <long long> d;
long long n;

void input () {
  scanf ("%lld", &n);

  solve ();
}

void solve () {
  int flag = 0;
  for (long long i = 2; (i*i) <= n; i++)
    if (n % i == 0) {
      flag = 1;
      break;
    }

  if (flag) {
    long long aux = n;
    for (long long i = 2; (i*i) <= aux; i++)
      while (aux % i == 0) {
        d.insert (i);
        aux /= i;
      }

    if (aux > 1)
      d.insert (aux);

    if (d.size () == 0)
      printf ("%lld\n", n);
    else if (d.size () == 1)
      printf ("%lld\n", *d.begin ());
    else
      printf ("%lld\n", (long long)1);
  }
  else
      printf ("%lld\n", n);
}

int main () {
  input ();
  return 0;
}
