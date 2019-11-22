#include <bits/stdc++.h>

std::map <char, int> cp, txt;

int main () {
  int n; std::cin >> n;
  for (int T = 0; T < n; T++) {
    cp.clear ();
    txt.clear ();
    int k; std::cin >> k;
    for (int i = 0; i < k; i++) {
      int b; char a;
      std::cin >> a >> b;
      cp [a] = b;
    }
    std::cin >> k;
    std::cin.ignore ();
    std::string str;
    for (int i = 0; i < k; i++) {
      getline (std::cin, str);
      for (int j = 0; j < str.size (); j++) {
        txt [str [j]]++;
      }
    }

    unsigned long long ans = 0;
    for (auto i = txt.begin (); i != txt.end (); i++) {
      //printf ("{%c, %d}\n", i->first, i->second);
      ans += (unsigned long long)cp [i->first] * (unsigned long long)i->second;
    }
    printf ("%llu.", ans / 100);

    if (ans % 100 < 10)
      printf ("0%llu$\n", ans % 100);
    else
      printf ("%llu$\n", ans % 100);
  }
  return 0;
}
