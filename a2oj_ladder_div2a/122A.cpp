#include <bits/stdc++.h>

int main () {
  int n; scanf ("%d", &n);

  for (int i = 1; i*i <= n; i++) {
    std::string s, t;
    if (n % i == 0) {
      int x = i;
      int y = n / i;

      while (x) {
        s += (char)((x % 10) + '0');
        x /= 10;
      }

      while (y) {
        t += (char)((y % 10) + '0');
        y /= 10;
      }
    }

    int f1 = 0, f2 = 0;
    if (s.size () == 0)
      f1 = 1;
    if (t.size () == 0)
      f2 = 1;

    for (int j = 0; j < s.size (); j++) {
      if (s[j] != '4' && s[j] != '7')
        f1 = 1;
    }

    for (int j = 0; j < t.size (); j++) {
      if (t[j] != '4' && t[j] != '7')
        f2 = 1;
    }

    /*
    std::cout << s << " : " << s.size ();
    printf (" | f1: %d\n", f1);
    std::cout << t << " : " << t.size ();
    printf (" | f2: %d\n", f2);
    */


    if (!f1 || !f2) {
      puts ("YES");
      return 0;
    }
  }

  puts ("NO");
  return 0;
}
