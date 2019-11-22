#include <bits/stdc++.h>

std::bitset <100> bm_a;
std::bitset <100> bm_b;
std::bitset <100> bm_c;

std::bitset <100> div (int x) {
  std::bitset <100> bs;
  //bs[0] = 1;
  for (int i = 1; i*i <= x; i++)
    if (x % i == 0) {
      bs[i-1] = 1;
      bs[(x / i) - 1] = 1;
    }
  return bs;
}

int main () {
  int a, b, c;
  scanf ("%d%d%d", &a, &b, &c);
  long long ans = (sqrt (a*c/b)) + (sqrt (a*b/c)) + (sqrt (b*c/a));
  printf ("%lld\n", ans * 4);
  return 0;
}
