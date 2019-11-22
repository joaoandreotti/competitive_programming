#include <bits/stdc++.h>

int main () {
  int n, k;
  scanf ("%d%d", &n, &k);
  std::string str;
  std::cin >> str;

  int t = n;
  for (int i = 1; i < n; i++)
    if (str.substr (0, i) == str.substr (n - i, i))
      t = n -i;

  for (int i = 0; i < k; i++)
    std::cout << str.substr (0, t);
  std::cout << str.substr (t, n);
  std::cout << '\n';
  return 0;
}
