#include <bits/stdc++.h>

void input ();
void solve ();

std::string str [4];

void input () {
  for (int i = 0; i < 4; i++)
    std::cin >> str [i];
  solve ();
}

void solve () {
  int flag = 0;

  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      int black = 0, white = 0;
      for (int i = a; i < a + 2; i++)
        for (int j = b; j < b + 2; j++)
          if (str [i][j] == '.')
            white++;
          else
            black++;
      //printf ("{%d, %d} | {%d, %d}\n", a, b, black, white);
      if (abs (black - white) == 2 || abs (black - white) == 4)
        flag = 1;
    }
  }

  if (flag)
    puts ("YES");
  else
    puts ("NO");
}

int main () {
  input ();
  return 0;
}
