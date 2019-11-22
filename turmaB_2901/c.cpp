#include <bits/stdc++.h>

typedef std::vector <long long> pi;

pi factors (long long n) {
  pi ans;
  for (long long i = 2; (i*i) <= n; i++) {
    while (!(n%i)) {
      ans.push_back (i);
      n /= i;
    }
  }

  if (n > 1)
    ans.push_back (n);
  return ans;
}

int main () {
  long long n; scanf ("%lld", &n);
  pi fac = factors (n);

  if (fac.size () <= 1)
    puts ("1\n0");
  else if (fac.size () == 2)
    puts ("2");
  else {
    printf ("1\n%lld\n", (long long)fac [0] * (long long)fac [1]);
  }
  return 0;
}
