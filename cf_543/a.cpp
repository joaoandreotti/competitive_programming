#include <bits/stdc++.h>

const int MAXN = 1e2 + 1;
typedef std::pair <int, int> pi;
typedef std::vector <int> vi;
typedef std::vector <pi> vp;

int n, m, k, aux;
int sc [MAXN];
int rmd [MAXN];
vp arr [MAXN];
vi ids;


int main () {
  scanf ("%d%d%d", &n, &m, &k);

  for (int i = 0; i < n; i++) {
    scanf ("%d", &aux);
    arr [0].push_back ({aux, 0});
  }

  for (int i = 0; i < n; i++) {
    scanf ("%d", &aux);
    arr [aux].push_back ({arr [0][i].first, i + 1});
    sc [i + 1] = aux;
  }
  for (int i = 0; i < k; i++) {
    scanf ("%d", &aux);
    ids.push_back (aux);
  }
  for (int i = 1; i <= n; i++)
    std::sort (arr [i].begin (), arr [i].end ());
  std::sort (ids.begin (), ids.end ());

  long long ans = 0;
  for (int i = k - 1; i >= 0; i--) {
    //printf ("sc: %d, id: %d\n", sc [ids [i]], ids [i]);
    int flag = 0;
    if (rmd [ids [i]])
      continue;
    for (int j = arr [sc [ids[i]]].size () - 1; j >= 0; j--) {
      //printf ("{%d, %d}\n", arr [sc [ids[i]]][j].first, arr [sc [ids[i]]][j].second);
      //printf ("f: %d, s: %d\n", arr [sc [ids[i]]][j].second, ids [i]);
      if (arr [sc [ids[i]]][j].second != ids [i]) {
        if (!flag) {
          ans++;
          flag = 1;
        }
        rmd [ids [i]] = 1;
        arr [sc [ids [i]]][j] = std::make_pair (0, 0);
      }
      else {
        arr [sc [ids [i]]][j] = std::make_pair (0, 0);
        break;
      }
    }
    std::sort (arr [sc [ids [i]]].begin (), arr [sc [ids [i]]].end ());
  }

  printf ("%lld\n", ans);


  return 0;
}
