#include <bits/stdc++.h>

void input ();
void solve ();

int n;
std::string str;

void input () {
  scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    std::cin >> str;
    solve ();
  }
}

void solve () {
  int last = -1, first = -1;
  for (int i = 0; i < str.size (); i++) {
    if (str [i] == '1')
      last = i;
    if (str [i] == '1' && first == -1)
      first = i;
  }

  int ans = 0;
  for (int i = first; i < last; i++)
    if (str [i] == '0')
      ans++;

  printf ("%d\n", ans);
}

int main () {
  input ();
  return 0;
}
