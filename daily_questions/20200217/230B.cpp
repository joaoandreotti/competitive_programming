#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1, MAXP = 1e7 + 1;;

long long n;
long long arr [MAXN];

std::vector <long long> isp (MAXP + 1, true), p, spf (MAXP + 1);
void sieve () {
  isp [0] = false;
  isp [1] = false;

  for (int i = 2; i <= MAXP; i++) {
    if (isp [i]) {
      p.push_back (i);
      spf [i] = i;
    }

    for (long long j = 0; (j < p.size ()) && (i * p [j] < MAXP) && (p [j] <= spf [i]); j++) {
      isp [i * p [j]] = false;
      spf [i * p [j]] = p [j];
    }
  }
}

void input () {
  scanf ("%lld", &n);
  for (int i = 0; i < n; i++)
    scanf ("%lld", arr + i);

  solve ();
}

void solve () {
  sieve ();
  std::set <int> tp;


  for (int i = 0; i < n; i++) {
    long long x = *std::lower_bound (p.begin (), p.end (), arr [i] / (long long)sqrt (arr [i]));
    //printf ("{%lld, %lld}\n", x * x, arr [i]);
    if ((x * x) == arr [i])
      puts ("YES");
    else
      puts ("NO");
  }
}

int main () {
  input ();
  return 0;
}
