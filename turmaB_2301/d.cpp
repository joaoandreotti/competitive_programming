#include <bits/stdc++.h>

const int MAXN = 1e2, INF = 0x3f3f3f3f;

typedef std::pair <int, int> pi;
typedef std::vector <pi> vi;
typedef std::vector <vi> vvi;

int n, e, t, m;
int dist [MAXN];
vvi arr;

std::set <pi> set;

void f () {
  while(!set.empty()) { 
    pi top = *set.begin();
    set.erase(top);

    //printf ("top: {%d, %d}\n", top.first, top.second);

    if (top.first == dist [top.second])
      for (auto v : arr [top.second]) {
        if (dist [v.first] > (v.second + top.first)) {
          dist [v.first] = v.second + top.first;
          set.insert ({dist [v.first], v.first});
        }
      }
  }
}

int main () {
  scanf ("%d%d%d%d", &n, &e, &t, &m);

  arr.resize (n + 1);

  int a, b, c;
  for (int i = 0; i < m; i++) {
    scanf ("%d%d%d", &a, &b, &c);
    arr [b].push_back ({a, c});
  }

  memset (dist, 0x3f, sizeof dist);
  dist [e] = 0;

  set.insert ({0, e});
  f ();

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    //printf ("dist [%d]: %d\n", i, dist [i]);
    if (dist [i] <= t)
      ans++;
  }

  printf ("%lld\n", ans);


  return 0;
}
