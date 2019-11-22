#include <bits/stdc++.h>

const int MAXP = (int)1e7;

std::vector <int> v;
bool np [MAXP + 10];

void sieve () {
  np [1] = 1;

  for (int i = 2; (i*i) <= MAXP; i++) {
    if (!np [i]) {
      v.push_back (i);
      for (int j = (i*i); j <= MAXP; j += i)
        np [j] = 1;
    }
  }
}

int main () {
  sieve ();
  /*
  for (int i = 0; i < v.size (); i++)
    printf ("%d ", v [i]);
  puts ("");
  */
  int n;
  while (scanf ("%d", &n) && n != 0) {
    std::vector <int> fac;
    std::vector <int> chk;

    int k = 0;
    while (n && v [k] <= n) {
      if (n % v [k] == 0) {
        printf ("%d ", v [k]);
        fac.push_back (v [k]);
        n /= v [k];
      }
      else
        k++;
    }
    puts ("");

    for (int i = 0; i < fac.size (); i++) {
      if (i > 0 && fac [i] == fac [i - 1])
        continue;
      for (int j = i + 2; j < fac.size (); j++) {
        printf ("%d ", fac [i] * fac [j]);
      }
      puts ("");
    }
  }
  return 0;
}
