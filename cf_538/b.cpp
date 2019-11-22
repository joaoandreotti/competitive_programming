#include <bits/stdc++.h>

const int MAXN = 1e5 + 1;

typedef std::pair <int, int> pi;
typedef std::vector <pi> vpi;

vpi vec;

int main () {
  int n, m, k; scanf ("%d%d%d", &n, &m, &k);

  for (int i = 0; i < n; i++) {
    int a; scanf ("%d", &a);
    vec.push_back ({a, i});
    //printf ("%d ", sum [i]);
  }
  //puts ("");

  std::sort (vec.begin (), vec.end ());

  std::vector <int> s;
  int count = 0;
  long long ans = 0;
  for (int i = vec.size () - 1; i >= 0 && count < (k * m); i--) {
    //printf ("{%d, %d} ", vec [i].first, vec [i].second);
    ans += vec [i].first;
    s.push_back (vec [i].second + 1);
    count++;
  }
  //puts ("");
  std::sort (s.begin (), s.end ());

  printf ("%lld\n", ans);
  count = 0;
  for (auto i = m - 1; i < s.size () && count < k-1; i += m) {
    printf ("%d ", s [i]);
    count++;
  }
  puts ("");


  return 0;
}
