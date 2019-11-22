#include <bits/stdc++.h>

void input ();
void solve ();

typedef std::tuple <int, int, int, int, int> query;
typedef std::vector <query> vq;
typedef std::pair <int, int> pi;

const int MAXN = 4e2 + 1, MAXM = 1e5 + 1;
const int INF = 0x3f3f3f3f;

int n, m, q;
int dst [MAXN][MAXN];
int ans [MAXM];
pi arr [MAXN];
vq qrs [2][MAXN];

void fw (int type) {
  int tmp [MAXN][MAXN];
  memcpy (tmp, dst, sizeof tmp);

  int numK = 0;
  // fw on sorted temperatures
  for (int k = 0; k < n; k++) {
    // if a new temperature has arived call query
    if (k && arr [k - 1].first != arr [k].first) {
      numK++;
      for (int l = 0; l < qrs [type][numK].size (); l++)
        ans [std::get <4> (qrs [type][numK][l])] = tmp [std::get <0> (qrs [type][numK][l])][std::get <1> (qrs [type][numK][l])];
    }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        tmp [i][j] = std::min (tmp [i][j], tmp [i][arr [k].second] + tmp [arr [k].second][j]);
  }
  //if (k && arr [k - 1].first != arr [k].first) {
  numK++;
  for (; numK <= n; numK++)
    for (int l = 0; l < qrs [type][numK].size (); l++)
      ans [std::get <4> (qrs [type][numK][l])] = tmp [std::get <0> (qrs [type][numK][l])][std::get <1> (qrs [type][numK][l])];
  //}


}

void input () {
  //freopen ("i.in", "r", stdin);
  scanf ("%d%d", &n, &m);

  memset (dst, 0x3f, sizeof dst);
  for (int i = 0, a; i < n && scanf ("%d", &a); i++) {
    arr [i] = {a, i};
    dst [i][i] = 0;
  }

  for (int i = 0, a, b, c; i < m && scanf ("%d%d%d", &a, &b, &c); i++) {
    a--; b--;
    dst [a][b] = c;
    dst [b][a] = c;
  }

  scanf ("%d", &q);
  for (int i = 0, a, b, c, d; i < q && scanf ("%d%d%d%d", &a, &b, &c, &d); i++) {
    a--; b--;
    qrs [d][c].push_back (std::make_tuple (a, b, c, d, i));
  }

  solve ();
}

void solve () {
  std::sort (arr, arr + n);

  fw (0);

  for (int i = 0; i < n; i++)
    arr [i].first = -arr [i].first;

  std::sort (arr, arr + n);

  fw (1);

  for (int i = 0; i < q; i++)
    printf ("%d\n", ans [i] == INF ? -1 : ans [i]);
}

int main () {
  input ();
  return 0;
}
