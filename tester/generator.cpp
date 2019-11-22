#include <bits/stdc++.h>

int rand(int a, int b) {
  return rand() % (b - a + 1) + a;
}

int32_t main(int argc, char* argv[]) {
  srand(atoi(argv[1]));

  int n, q, l;
  n = rand(2, 10);
  q = rand(1, 3);
  //l = rand(60, 170);
  l = 1;
  printf("%d %d %d\n", n, q, l);

  for (int i = 0; i < q; i++) {
    int l, r, m;
    l = rand(1, n-1);
    r = rand(l+1, n);
    //m = rand(1, 220);
    m = 2;
    printf("%d %d %d\n", l, r, m);
  }

  return 0;
}
