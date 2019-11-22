#include <bits/stdc++.h>

std::string cb [100], w[100], b[100];

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    std::cin >> cb [i];
    w [i] = cb [i];
    b [i] = cb [i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cb[i][j] == '.') {
        if (i % 2)
          if (j % 2)
            cb [i][j] = 'W';
          else
            cb [i][j] = 'B';
        else 
          if (!(j % 2))
            cb [i][j] = 'W';
          else
            cb [i][j] = 'B';
      }
    }
  }

  for (int i = 0; i < n; i++)
    std::cout << cb[i] << '\n';
  
  return 0;
}
