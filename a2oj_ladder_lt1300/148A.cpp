#include <bits/stdc++.h>

std::set <int> drag;

int main () {
  int k, l, m, n, d;
  scanf ("%d%d%d%d%d", &k, &l, &m, &n, &d);
  
  for (int i = k; i <= d; i += k)
    drag.insert (i);
  for (int i = l; i <= d; i += l)
    drag.insert (i);
  for (int i = m; i <= d; i += m)
    drag.insert (i);
  for (int i = n; i <= d; i += n)
    drag.insert (i);

  printf ("%d\n", (int)drag.size ());
  return 0;
}
