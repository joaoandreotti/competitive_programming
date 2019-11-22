#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>

int main () {
  int n;
  scanf ("%d", &n);
  int v[n];
  int best = 0;

  for (int i = 0; i < n; i++) {
    scanf ("%d", &v[i]);
  }

  int cont = 0;
  for (int i = 0; i < (n - 1); i++) {
    //auto x = std::lower_bound (v, v+n, v[i]);
    //auto y = std::upper_bound (v, v+n, v[i]*2);
    //std::cout << *x << " | " << *(y) << "; " << 2 * *x << "; " << *(y) << std::endl;
    if (v[i]*2 >= v[i + 1])
      cont++;
    else
      cont = 0;
    best = std::max (best, cont);
  }
  printf ("%d\n", ++best);


  return 0;
}

