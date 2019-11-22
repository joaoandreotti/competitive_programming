#include <bits/stdc++.h>

typedef std::vector <int> vi;

vi p, rank, set_size;

void init (int n) {
  set_size.assign (n, 1);
  rank.assign (n, 0);
  p.assign (n, 0);
  for (int i = 0; i < n; i++)
    p [i] = i;
}
int find_set (int i) {
  return (p [i] == i) ? i : (p [i] = find_set (p[i]));
}
bool same_set (int i, int j) {
  return find_set (i) == find_set (j);
}
void union_set (int i, int j) {
  if (!same_set (i, j)) {
    int x = find_set (i);
    int y = find_set (j);
    if (rank [x] > rank [y]) {
      p [y] = x;
      set_size [x] += set_size [y];
    }
    else {
      p [x] = y;
      set_size [y] += set_size [x];
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
}

int main () {
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    p.clear ();
    rank.clear ();
    set_size.clear ();

    init (n + 1);
  }
  return 0;
}
