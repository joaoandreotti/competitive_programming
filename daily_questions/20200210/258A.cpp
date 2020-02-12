#include <bits/stdc++.h>

void input ();
void solve ();

std::string str;

void input () {
  std::cin >> str;
  solve ();
}

void solve () {
  int pos = -1, hone = -1;

  std::reverse (str.begin (), str.end ());

  for (int i = str.size () - 1; i >= 0; i--) {
    //printf ("pos: %d, hone: %d, str [%d]: %c\n", pos, hone, i, str [i]);
    if (str [i] == '0') {
      pos = i;
      break;
    }

    if (hone == -1 && str [i] == '1')
      hone = i;
  }

  if (pos == -1)
    pos = hone;

  str [pos] = '0';

  //printf ("pos: %d, hone: %d\n", pos, hone);

  int flag = 0;
  for (int i = str.size () - 1; i >= 0; i--) {
    if (str [i] == '1')
      flag = 1;

    if (flag && i != pos)
      printf ("%c", str [i]);
  }

  puts ("");
}

int main () {
  input ();
  return 0;
}
