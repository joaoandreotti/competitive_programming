#include <bits/stdc++.h>

int main () {
  int n;
  std::string str;
  std::cin >> n >> str;
  long long ans = 0;
  char last = str[0];
  for (int i = 1; i < n; i++) {
    if (last == str[i])
      ans++;
    last = str[i];
  }
  
  printf ("%lld\n", ans);
  return 0;
}
