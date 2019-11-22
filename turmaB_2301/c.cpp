#include <bits/stdc++.h>

typedef std::vector <int> vi;
typedef std::vector <vi> vvi;

const int maxbm = (int)pow (2, 26);

vvi grp;
int n, m;
std::vector <std::string> ans;
std::string dp [26][maxbm];

void dfs (int x, int p, int bm, std::string a) {
  bm |= 1 << x;
  a += x + 'A';

  //printf ("{%c, %c}: ", p + 'A', x + 'A');

  //printf ("vis.size: %d: ", vis.size ());

  int count = 0;
  for (int i = 31; i >= 0; i--) {
    if ((bm >> i) & 1) {
      count++;
    }
  }
  //printf ("count: %d\n", count);

  if (count == n) {
    //std::cout << a << '\n';
    ans.push_back (a);
    return;
  }

  for (int n : grp [x]) {
    if (!((bm >> n) & 1)) {
      dfs (n, x, bm, a);
    }
  }
}

int main () {
  int T; scanf ("%d", &T);
  int cs = 1;

  while (T--) {
    scanf ("%d%d", &n, &m);

    grp.clear ();
    ans.clear ();
    grp.resize (26);
    vi vtx;

    char a, b;
    for (int i = 0; i < n; i++) {
      scanf (" %c", &a);
      //printf ("a: %c\n", a);
      vtx.push_back (a - 'A');
    }

    for (int i = 0; i < m; i++) {
      scanf (" %c %c", &a, &b);
      //printf ("a: %c, b: %c\n", a, b);
      a -= 'A';
      b -= 'A';
      grp [a].push_back (b);
      grp [b].push_back (a);
    }

    int bm = 0;
    std::string str;
    dfs (vtx[0], vtx[0], bm, str);

    std::sort (ans.begin (), ans.end ());
    printf ("Case %d: ", cs++);
    int flag = 0;
    for (int i = 0; i < ans.size (); i++) {
      if (ans [i][ans[i].size () - 1] == (vtx [vtx.size () - 1] + 'A')) {
        std::cout << ans [i] << '\n';
        flag = 1;
        break;
      }
    }
    if (!flag)
      printf ("impossible\n");
  }

  return 0;
}
