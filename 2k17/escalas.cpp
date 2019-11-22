#include <bits/stdc++.h>

const int mod = 12;

std::string notas[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
std::map <int, int> map, aux;

int main () {
  int n;
  scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    int a;
    scanf ("%d", &a);
    map[(a-1)%mod]++;
  }


  for (int i = 0; i < 12; i++){ // 12 num notas
    //puts ("-----------------------");
    int count = i;
    aux = map;

    //for (auto i = 0; i < 12; i++) {
      //printf ("st: %d, nd: %d\n", i, aux[i]);
    //}

    //printf ("i: %d, count: %d, map[count]: %d\n", i, count % mod, aux[count % mod]);
    if (aux[count % mod])
      aux [count % mod]--;

    if (aux[(count + 1) % mod])
      continue;

    count += 2;
    //printf ("i: %d, count: %d, map[count]: %d\n", i, count % mod, aux[count % mod]);
    if (aux[count % mod])
      aux [count % mod]--;

    if (aux[(count + 1) % mod])
      continue;

    count += 2;
    //printf ("i: %d, count: %d, map[count]: %d\n", i, count % mod, aux[count % mod]);
    if (aux[count % mod])
      aux [count % mod]--;

    count += 1;
    //printf ("i: %d, count: %d, map[count]: %d\n", i, count % mod, aux[count % mod]);
    if (aux[count % mod])
      aux [count % mod]--;

    if (aux[(count + 1) % mod])
      continue;

    count += 2;
    //printf ("i: %d, count: %d, map[count]: %d\n", i, count % mod, aux[count % mod]);
    if (aux[count % mod])
      aux [count % mod]--;

    if (aux[(count + 1) % mod])
      continue;

    count += 2;
    //printf ("i: %d, count: %d, map[count]: %d\n", i, count % mod, aux[count % mod]);
    if (aux[count % mod])
      aux [count % mod]--;

    if (aux[(count + 1) % mod])
      continue;

    count += 2;
    //printf ("i: %d, count: %d, map[count]: %d\n", i, count % mod, aux[count % mod]);
    if (aux[count % mod])
      aux [count % mod]--;

    count += 1;
    //printf ("i: %d, count: %d, map[count]: %d\n", i, count % mod, aux[count % mod]);
    if (aux[count % mod])
      aux [count % mod]--;

    if (aux[(count + 1) % mod])
      continue;

    printf ("%s\n", notas[i].c_str ());
    return 0;
  }

  printf ("desafinado\n");
  return 0;
}
