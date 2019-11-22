#include <bits/stdc++.h>

int main () {
  std::string board, hand [5];
  std::cin >> board;

  for (int i = 0; i < 5; i++)
    std::cin >> hand [i];


  int flag = 0;
  for (int i = 0; i < 5; i++) {
    if (hand [i][0] == board[0] || hand [i][1] == board[1])
      flag = 1;
  }
  if (flag)
    puts ("YES");
  else
    puts ("NO");
  return 0;
}
