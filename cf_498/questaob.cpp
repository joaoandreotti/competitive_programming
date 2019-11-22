#include <bits/stdc++.h>

bool func (std::pair <int, int> a, std::pair <int, int> b) {
  return a.second < b.second;
}

int main () {
  int n, k;
  scanf ("%d%d", &n, &k);

  int bests [k], ppd[k];
  std::vector <std::pair <int, int> > v, aux;

  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    //v.push_back ({a, i});
    aux.push_back ({a, i + 1});
  }

  std::sort (aux.begin (), aux.end ());
  std::sort (aux.begin () + n - k, aux.end (), func);

  int count = 0, sum = 0;;
  //printf ("fs: \n");
  for (int i = n - k; i < n; i++) {
    //printf ("%d %d\n", aux[i].first, aux[i].second);
    sum += aux [i].first;
  }

  printf ("%d\n", sum);

  sum = 0;
  if (k == 1) {
    printf ("%d\n", n);
    return 0;
  }
  for (int i = n - k; i < n; i++)
    if (i == n - k)
      printf ("%d ", abs(aux[i].second));
    else if (i + 1 < n)
      printf ("%d ", abs(aux[i].second - aux [i-1].second));
    else if (i + 1 >= n)
      printf ("%d ", abs(n - aux [i-1].second));

  return 0;
}
