#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

int t, n, m;
int arr [MAXN];
std::map <int, int> map;

void input () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d%d", &n, &m);

    map.clear ();
    for (int i = 0; i < m; i++)
      scanf ("%d", arr + i);

    solve ();
  }
}

void solve () {
  for (int i = 0; i < m; i++)
    map [arr [i]]++;

  int sum = 0;
  int count = 0;
  for (int i = 31; i >= 0; i--)
    if ((n >> i) & 1) {
      if (map [1 << i] > 0) {
        map [1 << i]--;
        sum += 1 << i;
        if (!map [1 << i])
          map.erase (1 << i);
      }
      else {
        // need to divide a higher number
        for (auto x = map.begin (); x != map.end (); x++)
          if (x->first > (1 << i)) {
            x->second--;
            int aux = x->first;
            while (aux > (1 << i)) {
              map [aux / 2]++;
              aux /= 2;
              printf ("dividing: %d\n", aux);
              count++;
            }
            sum += (1 << i);

            if (!x->second)
              map.erase (x->first);

            break;
          }
      }
    }

  if (sum != n)
    puts ("-1");
  else
    printf ("%d\n", count);
}

int main () {
  input ();
  return 0;
}
