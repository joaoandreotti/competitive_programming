#include <bits/stdc++.h>

#define LSOne(x) (x & (-x))

int n;

int main () {
  std::string inpt;

  int count = 0;
  while (std::getline (std::cin, inpt)) {
    //std::cout << "input: " << inpt << '\n';
    std::vector <int> v;

    int a, offset, j = 0;
    while (sscanf (inpt.c_str () + j, "%d%n", &a, &offset) != EOF) {
      v.push_back (a);
      j += offset;
    }

    long long ans = 0, best = 0;
    for (int i = 0; i < v.size (); i++) {
      ans = std::max ((long long)v [i], ans + v [i]);
      best = std::max (best, ans);
    }

    printf ("%lld\n", best);

  }


  return 0;
}
