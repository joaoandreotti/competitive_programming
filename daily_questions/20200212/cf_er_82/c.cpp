#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 26;

std::vector <std::set <int> > g;
std::string ans, str;

int t;
int vis [MAXN];

void dfs (int x) {
  vis [x] = 1;

  ans += x + 'a';

  for (int v : g [x])
    if (!vis [v])
      dfs (v);
}

void input () {
  scanf ("%d", &t);
  
  while (t--) {
    g.clear ();
    g.resize (MAXN);
    ans = "";
    memset (vis, 0, sizeof (vis));
    std::cin >> str;
    solve ();
  }
}

void solve () {
  for (int i = 0; i < str.size () - 1; i++) {
    g [str [i] - 'a'].insert (str [i + 1] - 'a');
    g [str [i + 1] - 'a'].insert (str [i] - 'a');
  }

  for (int i = 0; i < MAXN; i++)
    if (g [i].size () < 2 && !vis [i])
      dfs (i);

  int flag = 1;

  //printf ("CRR ANS: %s\n", ans.c_str ());
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++)
      if (ans [j] == i + 'a') {
        for (int k : g [i]) {
          //printf ("i: %d, j: %d, k: %d\n", i, j, k);
          if (j + 1 < MAXN && j - 1 >= 0) {
            if ((ans [j - 1] != k + 'a') && (ans [j + 1] != k + 'a')) {
              flag = 0;
              //puts ("aa");
            }
          }
          else if (j + 1 < MAXN) {
            if ((ans [j + 1] != k + 'a')) {
              flag = 0;
              //puts ("aa");
            }
          }
          else if (j - 1 >= 0) {
            if ((ans [j - 1] != k + 'a')) {
              flag = 0;
              //puts ("aa");
            }
          }
        }
      }



  if (flag && ans.size () == MAXN)
    std::cout << "YES\n" << ans << '\n';
  else
    puts ("NO");
}

int main () {
  input ();
  return 0;
}
