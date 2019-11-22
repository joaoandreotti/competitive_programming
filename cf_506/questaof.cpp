#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

bool ok (long long unsigned p1, long long unsigned p2) {
  return p1 <= p2;
}

int main () {
  long long unsigned a, b;
  //int v [10000010];
  std::vector <long long unsigned> v;
  scanf ("%I64u%I64u", &a, &b);
  long long unsigned best = 0x3f3f3f3f3f3f3f3fLL;
  long long unsigned sq = sqrt(a + b);

  for (long long unsigned i = 1; i <= sq; i++) {
    if ((a + b) % i == 0) {
      v.push_back ((a + b) / i);
    }
  }
  std::sort (v.begin (), v.end ());

  long long unsigned sqa = sqrt(a);
  for (long long unsigned j = 1; j <= sqa; j++) {
    if (a % j == 0) {
      long long unsigned x = a / j;
      long long unsigned k = 0 - 1;
      for (long long unsigned jmp = v.size (); jmp >= 1; jmp /= 2) {
        while (jmp + k < v.size () && !ok (x, v[jmp + k])) k += jmp;
      }
      k++;
      best = std::min (best, ((a+b)/v[k]) >= j ? ((v[k] + ((a + b) / v[k])) * 2) : best);
    }
  }
  long long unsigned sqb = sqrt(b);
  for (long long unsigned j = 1; j <= sqb; j++) {
    if (b % j == 0) {
      long long unsigned x = b / j;
      long long unsigned k = 0 - 1;
      for (long long unsigned jmp = v.size (); jmp >= 1; jmp /= 2) {
        while (jmp + k < v.size () && !ok (x, v[k+jmp])) k += jmp;
      }
      k++;
      best = std::min (best, ((a+b)/v[k]) >= j ? ((v[k] + ((a + b) / v[k])) * 2) : best);
    }
  }
  printf ("%I64u\n", best);
  return 0;
}
