#include <bits/stdc++.h>

int main () {
  int n;
  scanf ("%d", &n);
  std::string a, b;
  int bit;
  std::cin >> a >> b;

  int conta = 0, contb = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1')
      conta++;
    if (b[i] == '0')
      contb++;
  }

  if ((conta) >= n/2)
    printf ("%d\n", contb * (n - conta));
  else
    printf ("%d\n", contb * (conta));

  /*
  std::vector <std::pair <std::pair <char, char>, bool> > rel;

  for (int i = 0; i < n; i++)
    rel.push_back ({{a[i], b[i]}, false});

  for (int i = 0; i < n; i++) {
    if (rel[i].first.second == '0') { // se b == 0 muda

    }
  }
  */

  return 0;
}
