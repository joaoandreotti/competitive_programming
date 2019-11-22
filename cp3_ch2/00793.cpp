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
    std::cin.ignore ();
    p.clear ();
    rank.clear ();
    set_size.clear ();

    init (n + 1);

    char a;
    int b, c;
    int rans=0, wans=0;
    std::string str;
    while (getline (std::cin, str) && str.size () > 1) {
      if (sscanf (str.c_str(), " %c%d%d", &a, &b, &c)) {
        //printf ("%c, %d, %d\n", a, b, c);

        if (a == 'c') {
          union_set (b, c);
        }
        else {
          if (same_set (b, c))
            rans++;
          else
            wans++;
        }
      }
    }


    if (T)
      printf ("%d,%d\n\n", rans, wans);
    else
      printf ("%d,%d\n", rans, wans);
  }
  return 0;
}
