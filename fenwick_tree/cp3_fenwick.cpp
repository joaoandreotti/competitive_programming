#include <bits/stdc++.h>

#define LSOne(x) (x & (-x))

typedef std::vector <int> vi;
vi ft;
int n;
int q;

void insert (int num, int freq) {
  int x = num;
  // o num vai de num e se atualiaza com num += (LSOne (num))
  // ate que preencher todas as posicoes possiveis com
  // ft [num] += freq
  for (; num < ft.size (); num += (num & (-num))) {
    ft [num] += freq;
    printf ("num: %d, freq: %d, ft: %d\n", num, freq, ft [num]);
  }
}

int rsq(int num) { // returns RSQ(1, b)
  int sum = 0;
  // o num faz o processo inverso do insert assim,
  // como no insert ele vai crescendo, na busca ele 
  // diminui
  for (; num; num -= LSOne(num)) {
    printf ("num: %d, ft[num]: %d\n", num, ft[num]);
    sum += ft[num];
  }
  return sum; 
}

int rsq(int a, int b) { // returns RSQ(a, b)
  // se a == 1 retorna rsq (b) - 0
  // se a != 1 retorna rsq (b) - rsq (a - 1)
  // assim "excluindo" a parte do range antes de 'a'
  return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
}

int main () {
  scanf ("%d", &n);
  ft.assign (n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int a;
    puts ("NEW");
    scanf ("%d", &a);
    insert (i, a);
  }

  for (int i = 1; i < ft.size (); i++)
    printf ("%d ", ft [i]);
  puts ("");

  printf ("rsq : %d\n", rsq (3, 3));
  return 0;
}
