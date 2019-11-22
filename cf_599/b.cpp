#include <bits/stdc++.h>

void input ();
void solve ();

int t, n;
std::string a, b;

void input () {
  scanf ("%d", &t);
  for (int cs = 0; cs < t; cs++) {
    scanf ("%d", &n);
    std::cin >> a >> b;

    solve ();
  }
}

void solve () {
  std::vector <int> diff;
  for (int i = 0; i < n; i++)
    if (a [i] != b [i])
      diff.push_back (i);

  if (diff.size () == 2) {
    std::swap (a [diff [0]], b [diff [0]]);
    if (a == b) {
      puts ("Yes");
      return;
    }
    std::swap (a [diff [0]], b [diff [0]]);

    std::swap (a [diff [0]], b [diff [1]]);
    if (a == b) {
      puts ("Yes");
      return;
    }
    std::swap (a [diff [0]], b [diff [1]]);

    std::swap (a [diff [1]], b [diff [0]]);
    if (a == b) {
      puts ("Yes");
      return;
    }
    std::swap (a [diff [1]], b [diff [0]]);

    std::swap (a [diff [1]], b [diff [1]]);
    if (a == b) {
      puts ("Yes");
      return;
    }
    std::swap (a [diff [1]], b [diff [1]]);

    puts ("No");
  }
  else
    puts ("No");
}

int main () {
  input ();
  return 0;
}
