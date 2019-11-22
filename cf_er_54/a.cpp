#include <bits/stdc++.h>

int main () {
  int n; scanf ("%d", &n);
  std::string str;
  std::cin >> str;

  int flag = 0;
  for (int i = 0; i < (n - 1); i++) {
    if (!flag && str [i] > str[i + 1]) {
      flag = 1;
      continue;
    }
    printf ("%c", str [i]);
  }

  if (flag)
    printf ("%c", str [n - 1]);

  puts ("");
  return 0;
}
