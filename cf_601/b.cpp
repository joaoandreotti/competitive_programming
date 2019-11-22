#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e3 + 1;

int t, n, m;
std::pair <int, int> arr [MAXN];

void input () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
      arr [i].second = i;
      scanf ("%d", &arr [i].first);
    }

    solve ();
  }
}

void solve () {
  if (m < n || n <= 2) {
    puts ("-1");
    return;
  }

  std::sort (arr, arr + n);

  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += arr [i].first + arr [(i + 1) % n].first;

  printf ("%lld\n", ans);
  for (int i = 0; i < n; i++)
    printf ("%d %d\n", arr [i].second + 1, arr [(i + 1) % n].second + 1);

}

int main () {
  input ();
  return 0;
}
