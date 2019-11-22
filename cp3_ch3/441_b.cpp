#include <bits/stdc++.h>

const int MAXN = 13, MAXC = 6;
int n;
int arr [MAXN];

void comb (int pos, std::vector <int> a) {
  if (pos > n)
    return;
  if (a.size () == MAXC) {
    for (int i = 0; i < a.size (); i++) {
      if (i + 1 < a.size ())
        printf ("%d ", a [i]);
      else
        printf ("%d\n", a [i]);
    }
  }
  else {
    a.push_back (arr [pos]);
    comb (pos + 1, a);
    a.pop_back ();
    comb (pos + 1, a);
  }
}

int main () {
  int count = 0;
  while (scanf ("%d", &n) && n) {
    if (count++ > 0)
      puts ("");
    for (int i = 0; i < n; i++)
      scanf ("%d", arr + i);

    std::vector <int> a;
    comb (0, a);
  }
  return 0;
}
