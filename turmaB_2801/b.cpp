#include <bits/stdc++.h>

const int MAXN = 5e5 + 1;

int n, k, arr [MAXN];
std::vector <int> cc;
std::set <int> ans;

void f1 (int p , int v) {
  //printf ("{v: %d}", v);
  ans.insert (v);
  if (p >= cc.size ())
    return;

  f1 (p + 1, v);
  f1 (p + 1, v + cc [p]);
}


void f (int p, std::vector <int> c, int v) {
  if (v == k) {
    //printf ("v: %d, k: %d\n", v, k);
    cc = c;
    /*
    puts ("c:");
    for (int i = 0; i < c.size (); i++)
      printf ("%d ", c [i]);
    puts ("\n--");
    puts ("v:");
    */
    f1 (0, 0);
    //puts ("\n--");
  }
  if (p > n)
    return;
  
  f (p + 1, c, v);
  c.push_back (arr [p]);
  f (p + 1, c, v + arr [p]);
}

int main () {
  scanf ("%d%d", &n, &k);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);

  std::vector <int> aux;
  f (0, aux, 0);

  printf ("%d\n", ans.size ());
  for (auto i = ans.begin (); i != ans.end (); i++)
    printf ("%d ", *i);
  puts ("");
  return 0;
}
