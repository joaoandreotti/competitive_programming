#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> vps;
  long long n, sum = 0;
  int t, p=0;

  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    scanf("%lld", &n);
    vps.push_back(n);
  }

  sort(vps.begin(), vps.end());

  while (sum + 1 >= vps[p] && p < vps.size())
    sum += vps[p++];

  printf("%lld\n", sum + 1);

  return 0;
}
  
