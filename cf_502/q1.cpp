#include <bits/stdc++.h>

bool func (std::pair <int, int> a, std::pair <int, int> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first > b.first;
}

int main () {
  int n, num1;
  scanf ("%d", &n);
  std::vector < std::pair <int, int> > score;
  for (int i = 0; i < n; i++) {
    score.push_back ({0, i + 1});
    for (int j = 0; j < 4; j++) {
      scanf ("%d", &num1);
      score [i].first += num1;
    }
  }
  std::sort (score.begin (), score.end (), func);
  /*
  for (int i = 0; i < n; i++)
    printf ("%d : %d\n", score[i].second, score[i].first);
    */

  int x = 0;
  for (int i = 0; i < n; i++)
    if (score[i].second != 1)
      x++;
    else
      break;

  printf ("%d\n", x + 1);

  return 0;
}

/*
*/
