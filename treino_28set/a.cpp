#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

int n;
std::string str;

void input () {
  scanf ("%d", &n);
  std::cin >> str;

  solve ();
}

void solve () {

  int mod = 0;

  for (int i = 1; i < n; i += 2) {
    if (str [i - 1] == str [i])
      if (str [i] == 'a') {
        mod++;
        str [i] = 'b';
      }
      else {
        mod++;
        str [i] = 'a';
      }
  }

  printf ("%d\n%s\n", mod, str.c_str ());
}

int main () {
  input ();
  return 0;
}
