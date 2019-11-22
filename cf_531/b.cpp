#include <bits/stdc++.h>

int arr [(int)5e5 + 10];
int colors[(int)5e5 + 10];
std::map <int, int> map;

int main () {
  int n, k; scanf ("%d%d", &n, &k);

  for (int i = 0; i < n; i++) {
    int a; scanf ("%d", &a);
    map [a]++;
    arr [i] = a;
  }

  for (auto x : map) {
    if (x.second > k) {
      puts ("NO");
      return 0;
    }
  }
  puts  ("YES");

  int max = k;
  for (int i = 0; i < n; i++) {
    if (!colors [arr [i]] && max >= 1 && map [arr [i]] <= max) {
      int aux = max;
      max -= map [arr [i]];
      map [arr [i]] = aux;
      colors [arr [i]] = 1;
    }
    printf ("%d ", (map [arr [i]]--));
  }
  puts ("");


  return 0;
}
