#include <bits/stdc++.h>

std::string a;

int check (int p, int k) {

  //printf ("a: %s, p: %d, k: %d\n", a.c_str (), p, k);
  int flag  = 0;

  int i = p;
  while (!flag || p != i) {
    if (a [i] == 'P') return 0;
    //printf ("i: %d\n", i);

    i += k;
    i %= a.size ();
    flag = 1;
  }
  return 1;
}

std::vector <int> divisors (int n) {
  std::vector <int> ans;
  ans.push_back (1);
  for (int i = 2; (i*i) <= n; i++)
    if (!(n % i)) {
      ans.push_back (i);
      if ((i*i) != n)
        ans.push_back (n / i);
    }

  return ans;
}

int gcd (int a, int b) {
  while (b) {
    a %= b;
    std::swap (a, b);
  }
  return a;
}

const int MAXN = 1e6 + 10;

int arr [MAXN];

int main () {
  while (std::cin >> a) {
    int n = a.size ();
    memset (arr, 0, n * 4);

    std::vector <int> div = divisors (n);


    //printf ("gcd (%d, %d): %d\n", 2, 6, std::__gcd (2, 6));
    for (int i = 0; i < div.size (); i++) {
      for (int j = 0; j < div [i]; j++)
        if (check (j, div [i]))
          arr [div [i]] = 1;
    }

    //puts ("arr:");
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      //printf ("%d ", arr [i]);
      ans += arr [gcd (i, n)];
    }
    //puts ("");

    printf ("%lld\n", ans);
  }
  return 0;
}
