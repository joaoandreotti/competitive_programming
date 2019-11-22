#include <bits/stdc++.h>

const int MAXN = 1e5;
const int MAXI = 0x3f3f3f3f;

typedef std::map <int, int> mi;
typedef std::vector <mi > vmi;
typedef std::vector <std::pair <int, int> > vpi;
vmi st;
int arr [MAXN + 1];

void build (int p, int L, int R) {
  if (L == R) {
    mi x;
    x[arr [L]]++;
    st [p] = x;
  }
  else {
    build ((p << 1), L, (L + R) / 2);
    build ((p << 1) + 1, ((L + R) / 2) + 1, R);
    mi p1 = st [(p << 1)];
    mi p2 = st [(p << 1) + 1];

    for (auto i = p1.begin (); i != p1.end (); i++)
      st [p][i->first] += i->second;
    for (auto i = p2.begin (); i != p2.end (); i++)
      st [p][i->first] += i->second;

    /*
    st [p].insert (p1.begin (), p1.end ());
    st [p].insert (p2.begin (), p2.end ());
    */
  }
}

mi rq (int p, int L, int R, int i, int j) {
  //printf ("(%d), [%d, %d], [%d, %d]\n", p, i, j, L, R);
  if (i > R || j < L) {
    mi x;
    return x;
  }
  if (L >= i && R <= j)
    return st [p];

  mi p1 = rq ((p << 1), L, (L + R) / 2, i, j);
  mi p2 = rq ((p << 1) + 1, ((L + R) / 2) + 1, R, i, j);

  if (!p1.size ())
    return p2;
  if (!p2.size ())
    return p1;

  mi x;
  for (auto i = p1.begin (); i != p1.end (); i++)
    x [i->first] += i->second;
  for (auto i = p2.begin (); i != p2.end (); i++)
    x [i->first] += i->second;

  return x;

}

int main () {
  int N, Q;
  while (scanf ("%d", &N) && N) {
    scanf ("%d", &Q);
    st.clear ();
    int nxt_pwr = (int)pow (2, ceil (log2 (N))) * 2;

    for (int i = 1; i <= N; i++)
      scanf ("%d", arr + i);

    st.resize (nxt_pwr);

    build (1, 1, N);

    /*
    for (int i = 1; i < nxt_pwr; i++) {
      printf ("Printing the %dth node: \n", i);
      for (auto j = st [i].begin (); j != st [i].end (); j++) {
        printf ("(%d, %d) ", j->first, j->second);
      }
      puts ("");
    }
    puts ("");
    */

    int a, b;
    for (int i = 0; i < Q; i++) {
      scanf ("%d%d", &a, &b);
      mi ans = rq (1, 1, N, a, b);
      int max = 0;
      for (auto i = ans.begin (); i != ans.end (); i++)
        max = std::max (max, i->second);

      printf ("%d\n", max);
    }
    

  }
  return 0;
}
