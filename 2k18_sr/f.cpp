#include <bits/stdc++.h>

typedef std::vector <std::vector <std::pair<std::pair <int, int>, int> > > vvpi;
typedef std::vector <std::pair<std::pair <int, int>, int> > vpi;
vvpi stg;
int n;

long long ans = -1;

void func (int i, int j, int seen, vpi crr, long long max) {
  //printf ("(%d, %d)\n", i, j);
  if (seen == int(pow (2, n) - 1))
    ans = std::max (ans, max);
  //printf ("\tAsstiu: \n");
  for (int k = 0; k < crr.size (); k++) {
    //printf ("\t\tShow %d: (%d, %d) : %d\n", k, crr[k].first.first, crr[k].first.second, crr[k].second);
  }
  //printf ("\tMAX: %lld\n", max);

  if (i >= stg.size ())
    return;
  if (j >= stg[i].size ()) {
    //printf ("\tMudou o palco\n");
    func (i + 1, 0, seen, crr, max);
    return;
  }
  //printf ("\tContinuou no palco\n");

  int itsc = 0;
  for (int k = 0; k < crr.size (); k++) {
    //printf ("\tTesting: (%d, %d) and (%d, %d) = ", stg[i][j].first.first, stg[i][j].first.second, crr[k].first.first, crr[k].first.second);
    //normal
    if (stg[i][j].first.first < crr[k].first.first && stg[i][j].first.second > crr[k].first.first)
      itsc = 1;
    if (stg[i][j].first.first < crr[k].first.second && stg[i][j].first.second > crr[k].first.second)
      itsc = 1;
    
    //invergado
    if (crr[k].first.first < stg[i][j].first.first && crr[k].first.second > stg[i][j].first.first)
      itsc = 1;
    if (crr[k].first.first < stg[i][j].first.second && crr[k].first.second > stg[i][j].first.second)
      itsc = 1;

    if (stg[i][j].first == crr[k].first)
      itsc = 1;
    //printf ("%d\n", itsc);
  }

  //printf ("\tNao Pegou: (%d, %d) : %d\n", stg[i][j].first.first, stg[i][j].first.second, stg[i][j].second);
  func (i, j + 1, seen, crr, max);
  if (!itsc) {
    //printf ("\tPegou: (%d, %d) : %d\n", stg[i][j].first.first, stg[i][j].first.second, stg[i][j].second);
    crr.push_back ({stg[i][j].first, stg[i][j].second});
    seen |= 1 << i;
    func (i, j + 1, seen, crr, max + stg[i][j].second);
  }
}

int main () {
  scanf ("%d", &n);
  stg.resize (n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    for (int j = 0; j < a; j++) {
      int s, e, p;
      scanf ("%d%d%d", &s, &e, &p);
      stg[i].push_back ({{s, e}, p});
    }
  }

  /*
  for (int i = 0; i < stg.size (); i++) {
    printf ("Palco %d:\n", i);
    for (int j = 0; j < stg[i].size (); j++) {
      printf ("Shows: (%d, %d) : %d\n", stg[i][j].first.first, stg[i][j].first.second, stg[i][j].second);
    }
  }
 */
  vpi a;
  func (0, 0, 0, a, 0);
  printf ("%lld\n", ans);

  return 0;
}
