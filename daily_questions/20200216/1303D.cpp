#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

long long t, n, m;
long long arr [MAXN];
std::map <long long, long long> map;

void input () {
  scanf ("%lld", &t);
  while (t--) {
    scanf ("%lld%lld", &n, &m);
    map.clear ();
    for (int i = 0; i < m; i++)
      scanf ("%lld", arr + i);

    solve ();
  }
}

void solve () {
  for (int i = 0; i < 31; i++)
    map [1 << i] = 0;
  for (int i = 0; i < m; i++)
    map [arr [i]]++;

  long long aaaaaaaaaaaaa = 0;
  for (auto i = map.begin (); i != map.end (); i++)
    aaaaaaaaaaaaa += i->first * i->second;
  if (aaaaaaaaaaaaa < n) {
    puts ("-1");
    return;
  }

  //for (auto i = map.begin (); i != map.end (); i++)
    //printf ("{%d, %d}\n", i->first, i->second);

  long long count = 0;
  // if bit 2^i in n is off, just merge every possible 2^i long longo 2^(i+1)
  for (long long i = 0; i < 31; i++) {
    long long aux = map [1 << i];

    if ((n >> i) & 1)
      if (map [1 << i] == 0) {
        // need to divide a higher number
        for (auto x = map.begin (); x != map.end (); x++)
          if (x->first > (1 << i) && x->second) {
            x->second--;
            long long aux = x->first;
            while (aux > (1 << i)) {
              //printf ("dividing: %d\n", aux);
              map [aux / 2]++;
              aux /= 2;
              count++;
            }

            if (!x->second)
              map.erase (x->first);

            break;
          }
        continue;
      }

    if ((n >> i) & 1) {
      map [1 << i] -= ((aux - 1) / 2) * 2;
      map [1 << (i + 1)] += ((aux - 1) / 2);
    }
    else {
      map [1 << i] -= (aux / 2) * 2;
      map [1 << (i + 1)] += (aux / 2);
    }
  }

  //for (auto i = map.begin (); i != map.end (); i++)
    //printf ("{%d, %d}\n", i->first, i->second);

  long long sum = 0;
  for (long long i = 30; i >= 0; i--) {
    //printf ("sum: %d, 1 << %d: %d\n", sum, i, 1 << i);
    if ((n >> i) & 1)
      if (map [1 << i] > 0) {
        map [1 << i]--;
        sum += 1 << i;
        if (!map [1 << i])
          map.erase (1 << i);
      }
  }
  //printf ("sum: %d\n", sum);

  //for (auto i = map.begin (); i != map.end (); i++)
    //printf ("{%d, %d}\n", i->first, i->second);
  printf ("%lld\n", count);
}

int main () {
  input ();
  return 0;
}
