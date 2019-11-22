#include <bits/stdc++.h>

long long n, m;

int f (long long x) {
  int count = 0;
  //printf ("x: %lld\n", x);
  for (long long i = 2; (i) <= x; i++) {
    while (x % i == 0) {
      x /= i;
      count++;
    }
    if (i > 3)
      return -1;
  }

  return count;
}

void input () {
  scanf ("%lld%lld", &n, &m);
}

void sol () {
  if (m % n != 0)
    puts ("-1");
  else
    if (n == 1 && n != m && !f (m / n))
      puts ("-1");
    else
      printf ("%d\n", f (m / n));
}

int main () {
  input ();
  sol ();
  return 0;
}
