#include <bits/stdc++.h>

typedef long long unsigned llu;
const int N = 2e5+10;
int n, pos, d[N];
llu clk[N], aclk[N], best;

int main () {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", d+i);
    clk[i] = i ? clk[i-1]+d[i] : d[i];
  }

  for (int i = n-1; i>= 0; i--)
    aclk[i] = (i<n-1) ? aclk[i+1]+d[i] : d[i];

  std::reverse(aclk, aclk+n);
  for (int i = 0; i < n-1; i++) {
    pos = std::lower_bound(aclk, aclk+n-i-2, clk[i]) - aclk;
    if (pos < n)
      //std::cout << clk[i] << " " << aclk[pos] << "\n";
    if (pos < n && aclk[pos] == clk[i])
      best = clk[i];
  }

  std::cout << best << "\n"; 
  return 0;
}
