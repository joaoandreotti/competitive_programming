#include <bits/stdc++.h>


// ****** RANGE MINIMUM QUERY ******

const int MAXN = 1e6;
const int MAXI = 0x3f3f3f3f;

typedef std::vector <int> vi;
vi st;
int arr [MAXN + 1];

void build (int p, int L, int R) { // p == crr node index, L and R crr node RQ [L, R]
  if (L == R) 
    st [p] = L; // storing the index
  else {
    build ((p << 1), L, (L + R) / 2); // left node and range
    build ((p << 1) + 1, ((L + R) / 2) + 1, R); // right node and range
    int p1 = st [(p << 1)]; // RQ from left node
    int p2 = st [(p << 1) + 1]; // RQ from right node
    if (arr [p1] <= arr [p2]) // in this case range minimum query (change if necessary)
      st [p] = p1;
    else
      st [p] = p2;
  }
}

int rq (int p, int L, int R, int i, int j) {
  printf ("(%d), [%d, %d], [%d, %d]\n", p, i, j, L, R);
  if (i > R || j < L) // if outside of RQ doesnt use the value
    return -1;
  if (L >= i && R <= j) // if ([L,R] C [i, j]) valid range and return its value
    return st [p];

  // if none of the above go down the tree
  int p1 = rq ((p << 1), L, (L + R) / 2, i, j); // check all left nodes
  int p2 = rq ((p << 1) + 1, ((L + R) / 2) + 1, R, i, j); // check all right nodes

  if (p1 == -1) // if p1 isnt valid then p2
    return p2;
  if (p2 == -1) // if p2 isnt valid then p1
    return p1;
  
  if (arr [p1] <= arr [p2]) // return the RQ in this case (Range minimum query)
    return p1;
  else
    return p2;
}

int update (int p, int L, int R, int idx, int value) {
  if (idx > R || idx < L) // if outside of the range, return the range value because it wont change
    return st [p];

  if (L == idx && R == idx) { // if leaf then update the arr [idx] value then return idx
    arr [idx] = value;
    return st [p] = idx;
  }

  int p1 = update ((p << 1), L, (L + R) / 2, idx, value); // check the left node
  int p2 = update ((p << 1) + 1, ((L + R) / 2) + 1, R, idx, value); // check the right node

  if (arr [p1] <= arr [p2]) // updating the new RQ value (range minimum query)
    return st [p] = p1;
  else
    return st [p] = p2;
}

int main () {
  int N; scanf ("%d", &N);
  int nxt_pwr = (int)pow (2, ceil (log2 (N))) * 2; // nxt_pwr == maximum number of nodes
  // nxt_pwr / 2 == maximum number of leafs
  printf ("nxt_pwr: %d\n", nxt_pwr);
  int sz = 4 * N; // size from CP3

  for (int i = 1; i <= N; i++) // normal input
    scanf ("%d", arr + i);
  //for (int i = N + 1; i < nxt_pwr; i++) // only needed for ghost nodes
    //arr [i] = MAXI;

  // printing the input array
  puts ("arr: ");
  for (int i = 0; i < nxt_pwr; i++)
    printf ("%d ", arr [i]);
  puts ("");

  // building the seg_tree
  st.assign (nxt_pwr, 0);
  build (1, 1, N); //index 1 represents segment [1, N] | (do not create ghost nodes) == no MLE
  //build (1, 1, nxt_pwr/2); //index 1 represents segment [1, nxt_pwr/2] (create ghost nodes)


  // PRINTING
  for (int i = 1; i < nxt_pwr; i++)
    printf ("(%d, %d) ", arr [st [i]], i);
  puts ("");

  // RQ (2, 5)
  printf ("rq: %d\n", arr [rq (1, 1, N, 2, 5)]); // p == root, L, R == root RQ | (without ghost node)
  // update (5, 7)
  update (1, 1, N, 5, 7);
  // RQ (2, 5)
  printf ("rq: %d\n", arr [rq (1, 1, N, 2, 5)]); // p == root, L, R == root RQ | (without ghost node)

  // PRINTING
  for (int i = 1; i < nxt_pwr; i++)
    printf ("(%d, %d) ", arr [st [i]], i);
  puts ("");


  return 0;
}
