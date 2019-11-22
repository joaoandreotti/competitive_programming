#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e2 + 1;

int n, m, cs;
long long arr [MAXN];

void input () {
  scanf ("%d", &n);
  for (cs = 1; cs <= n; cs++) {
    scanf ("%d", &m);
    for (int i = 0; i < m; i++)
      scanf ("%lld", arr + i);
    solve ();
  }
}

void solve () {
  long long best = 0, sum = 0;
  int max_count = 0;
  int count = 0;

  for (int i = 0; i < m; i++) {
    //sum = std::max (arr [i], sum + arr [i]);
    if (sum + arr [i] >= arr [i]) {
      sum += arr [i];
      count++;
    }
    else {
      sum = arr [i];
      count = 1;
    }

    //best = std::max (best, sum);
    if (best <= sum) {
      best = sum;
      max_count = count;
    }
  }

  printf ("Caso:%d || Janela:%d || SOMA: %lld\n", cs, max_count, best);
}

int main () {
  input ();
  return 0;
}
