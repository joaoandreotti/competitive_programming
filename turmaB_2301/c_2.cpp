#include <bits/stdc++.h>

typedef std::map <char, int> mci;
typedef std::vector <char> vc;
typedef std::vector <vc> vvc;

const int MAXN = 16, MAXM = 1 << 16;

char arr [MAXN];
int n, m;
bool done [MAXN][MAXM];
mci input;
vvc graph;
std::string dp [MAXN][MAXM];

std::string dfs (char x, int bm) {
  if (done [input [x]][bm])
    return dp [input [x]][bm];
  done [input [x]][bm] = true;

  bm |= 1 << input [x];
  std::string ans = "";
  ans += x;
  if (x == arr [n - 1] && (bm == ((1 << n) - 1)))
    return dp [input [x]][bm] = ans;

  for (char n : graph [input [x]]) {
    if (!((bm >> input [n]) & 1)) {
      std::string aux = dfs (n, bm);
      if (aux.size ())
        return dp [input [x]][bm] = ans + aux;
    }
  }

  return dp [input [x]][bm] = "";
}

int main () {
  int T, cs = 0; scanf ("%d", &T);


  while (T-- && ++cs) {
    scanf ("%d%d", &n, &m);

    graph.clear ();
    input.clear ();
    memset (done, 0, sizeof (done));

    graph.resize (n);


    for (int i = 0; i < n; i++) {
      scanf (" %c", arr + i);
      input [arr [i]] = i;
    }

    /*
    puts ("nodes: ");
    for (int i = 0; i < n; i++)
      printf ("%c ", arr [i]);
    puts ("");
    */

    for (int i = 0; i < m; i++) {
      int a, b; scanf (" %c %c", &a, &b);
      graph [input [a]].push_back (b);
      graph [input [b]].push_back (a);
    }

    for (int i = 0; i < graph.size (); i++)
      std::sort (graph [i].begin (), graph [i].end ());

    /*
    puts ("graph: ");
    for (int i = 0; i < n; i++) {
      printf ("%d: ", i);
      for (int j = 0; j < graph [i].size (); j++)
        printf ("%c ", graph [i][j]);
      puts ("");
    }
    */

    printf ("Case %d: ", cs);

    std::string ans = dfs (arr [0], 0);

    if (ans.size ())
      printf ("%s\n", ans.c_str ());
    else
      puts ("impossible");

  }

  return 0;
}
