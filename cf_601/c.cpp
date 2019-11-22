#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;


std::vector <int> ans;
int n;
int arr [MAXN][3];
int count [MAXN];

void f (int x) {
  if (!ans.empty ())
    return;

  if (x >= n - 2) {
    int flag = 1;
    for (int i = 0; i < n - 3; i++)
      if (arr [i][1] != arr [i + 1][0] || arr [i][2] != arr [i + 1][1])
        flag = 0;

    if (flag) {
      /*
      puts ("-----");
      for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++)
          printf ("%d ", arr [i][j]);
        puts ("");
      }
      puts ("-----");
      */
      ans.push_back (arr [0][0]);
      ans.push_back (arr [0][1]);
      ans.push_back (arr [0][2]);
      for (int i = 1; i <= n - 3; i++) {
        ans.push_back (arr [i][2]);
      }
    }

    return;
  }

  if (x == 0) {
    f (x + 1);
    std::swap (arr [x][1], arr [x][2]);
    f (x + 1);
  }
  else if (x == n - 3) {
    f (x + 1);
    std::swap (arr [x][0], arr [x][1]);
    f (x + 1);
  }
  else {
    std::sort (arr [x], arr [x] + 3);
    do {
      f (x + 1);
    } while (std::next_permutation (arr [x], arr [x] + 3));
  }
}

void input () {
  scanf ("%d", &n);

  for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < 3; j++) {
      scanf ("%d", arr [i] + j);
      count [arr [i][j]]++;
    }

  solve ();
}

void solve () {
  int st = 0, last = 0;
  for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < 3; j++) {
      if (count [arr [i][j]] == 1 && !st) {
        std::swap (arr [i][0], arr [i][j]);
        std::swap (arr [i], arr [0]);
        st = 1;
      }
      else if (count [arr [i][j]] == 1 && !last) {
        std::swap (arr [i][2], arr [i][j]);
        std::swap (arr [i], arr [n - 3]);
        last = 1;
      }
    }

  f (0);

  for (int i = 0; i < ans.size (); i++)
    if (i + 1 < ans.size ())
      printf ("%d ", ans [i]);
    else
      printf ("%d\n", ans [i]);
}

int main () {
  input ();
  return 0;
}
