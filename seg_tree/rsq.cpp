#include <bits/stdc++.h>

const int MAXN = 1e6 + 1;

typedef std::vector <int> vi;
vi st;
int arr [MAXN];

void build (int p, int L, int R) {
  //printf ("%d\n", L);
  if (L == R) {
    st [p] = arr [L];
    //printf ("st[%d] %d\n", p, st [p]);
  }
  else {
    build ((p << 1), L, (L + R) / 2);
    build ((p << 1) + 1, ((L + R) / 2) + 1, R);

    int p1 = st [(p << 1)];
    int p2 = st [(p << 1) + 1];

    //printf ("p: %d\n", p);
    st [p] += p1 + p2;
  }
  printf ("st [%d]: %d\n", p, st [p]);
}

int rq (int p, int L, int R, int i, int j) {
  if (i > R || j < L)
    return -1;

  if (L >= i && R <= j)
    return st [p];

  int p1 = rq ((p << 1), L, (L + R) / 2, i, j);
  int p2 = rq ((p << 1) + 1, ((L + R) / 2) + 1, R, i, j);

  if (p1 == -1)
    return p2;
  if (p2 == -1)
    return p1;


  return p1 + p2;
}

int update (int p, int L, int R, int idx, int value) {
  if (idx > R || idx < L)
    return st [p];

  if (L == idx && R == idx) {
    arr [idx] = value;
    return st [p] = idx;
  }


  int p1 = update ((p << 1), L, (L + R) / 2, idx, value);
  int p2 = update ((p << 1) + 1, ((L + R) / 2) + 1, R, idx, value);

  return st [p] += p1 + p2;
}


int main () {
  int N; scanf ("%d", &N);
  int nxt_pwr = (int)pow (2, ceil (log2 (N))) * 2;

  printf ("nxt_pwr: %d\n", nxt_pwr);

  for (int i = 1; i <= N; i++)
    scanf ("%d", arr + i);

  st.assign (nxt_pwr, 0);
  build (1, 1, N);

  //print
  for (int i = 0; i < nxt_pwr; i++)
    printf ("%d ", st [i]);
  puts ("");

  printf ("rq [4, 7]: %d\n", rq (1, 1, N, 4, 7));
  return 0;
}
