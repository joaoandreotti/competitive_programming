#include <bits/stdc++.h>

void input ();
void solve ();

std::string str, ss;

void input () {
  std::cin >> str >> ss;
  solve ();
}

void solve () {
  int count = 0;

  for (int i = 0; i < str.size (); i++) {
    if (str [i] == ss [count])
      count++;
  }

  if (count == ss.size ())
    puts ("YES");
  else
    puts ("NO");
}

int main () {
  input ();
  return 0;
}
