#include <bits/stdc++.h>

void input ();
void solve ();

int n;
std::string str;

void input () {
  scanf ("%d", &n);
  std::cin >> str;

  solve ();
}

void solve () {
  if (n % 2)
    puts ("No");
  else {
    if (str.substr (0, n / 2) == str.substr (n / 2, n / 2))
      puts ("Yes");
    else
      puts ("No");
  }
}

int main () {
  input ();
  return 0;
}
