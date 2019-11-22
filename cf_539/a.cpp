#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, v;
long long dp [(int)1e2 + 1][(int)1e2 + 1];

long long f (int c, int g) {
  if (dp [c][g] != INF)
    return dp [c][g];

  if (c == n)
    return dp [c][g] = 0;


  //printf ("c: %d, g: %d\n", c, g);
  for (int i = 0; i <= (v - g); i++) {
    if (g || i)
      dp [c][g] = std::min (dp [c][g], f (c + 1, (g + i) - 1) + (c * i));
  }

  return dp [c][g];
}

int main () {
  scanf ("%d%d", &n, &v);

  memset (dp, 0x3f, sizeof (dp));

  printf ("%lld\n", f (1, 1) + 1);
  return 0;
}
