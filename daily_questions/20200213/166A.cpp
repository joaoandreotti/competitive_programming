#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e2;

int n, k;
std::pair <int, int> arr [MAXN];
std::map <std::pair <int, int>, int> map;

bool cmp (std::pair <int, int> a, std::pair <int, int> b) {
  return std::make_pair (-a.first, a.second) < std::make_pair (-b.first, b.second);
}

void input () {
  scanf ("%d%d", &n, &k);

  for (int i = 0; i < n; i++)
    scanf ("%d%d", &arr [i].first, &arr [i].second);

  solve ();
}

void solve () {
  std::sort (arr, arr + n, cmp);
  for (int i = 0; i < n; i++) {
    map [arr [i]]++;
    //printf ("{%d, %d}", arr [i].first, arr [i].second);
  }
  //puts ("");


  printf ("%d\n", map [arr [k - 1]]);
}

int main () {
  input ();
  return 0;
}
