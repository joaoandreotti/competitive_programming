#include <bits/stdc++.h>

const int MAXN = 1e7 + 1;

std::vector <long long> isp (MAXN, true), p, spf (MAXN);

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

int main () {
  int n; scanf ("%d", &n);
  sieve ();

/*
  for (int i = 0; i < n; i++)
    printf ("%d ", p [i]);
  puts ("");
  */

  return 0;
}
