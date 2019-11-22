

#include <bits/stdc++.h>
using namespace std;

#define N 100010
int n, m;
], zero[], degree[N], vis[N];

int main()
{
  while (scanf("%d%d", &n, &m) != EOF)
  {
    memset(degree, , sizeof degree);
    cnt[] = cnt[] = ;
    zero[] = zero[] = ;
    ; i <= n; ++i)
    {
      scanf("%d", vis + i);
      ++cnt[vis[i]];
    }
    )
    {
      ; i <= n; ++i) printf(, " \n"[i == n]);
      continue;
    }
    , u, v; i <= m; ++i)
    {
      scanf("%d%d", &u, &v);
      if (vis[u] == vis[v]) continue;
      ++degree[u];
      ++degree[v];
    }
    ; i <= n; ++i) if (!degree[i])
      ++zero[vis[i]];
    ; i <= n; ++i)
    {
      ;
      + degree[i] + (cnt[vis[i] ^ ] - degree[i]) * ;
      + cnt[vis[i] ^ ] *  + zero[vis[i] ^ ];
      printf("%d%c", res, " \n"[i == n]);
    }
  }
  ;
}


