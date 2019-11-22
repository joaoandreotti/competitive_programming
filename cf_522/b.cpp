#include <bits/stdc++.h> 

const int MAXR = 5, MAXC = 20;

int main () {
  std::string str;
  std::cin >> str;

  int r = 0, c = 0;
  for (int i = 1; i <= MAXR; i++) {
    for (int j = 1; j <= MAXC; j++) {
      if (i * j >= str.size ()) {
        r = i;
        c = j;
        break;
      }
    }
    if (r)
      break;
  }
  printf ("%d %d\n", r, c);

  int ast = ((c * r) - str.size ());
  std::string ans [r];
  int max = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if ((i * c) + j < str.size ())
        ans[i] += str [(i * c) + j];
    }
    if (max < ans [i].size ())
      max = ans [i].size ();
  }

  for (int i = 0; i < r; i++) {
    std::cout << ans [i] << std::endl;
  }

  return 0;
}
