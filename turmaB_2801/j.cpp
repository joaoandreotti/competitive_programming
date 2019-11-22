#include <bits/stdc++.h>

const int MAXP = 25e4 + 1;
std::string a, b, ans;

int lps [MAXP], first;

void build_lps () {
  int i = 1, j = 0;
  lps [0] = 0;

  while (i < b.size ()) {
    if (b [i] == b [j]) {
      lps [i++] = ++j;
    }
    else {
      if (j == 0)
        lps [i++] = 0;
      else
        j = lps [j - 1];
    }
  }
}

void kmp () {
  int i = 0, j = 0;
  build_lps ();

  while (i < a.size ()) {
    if (a [i] == b [j]) {
      j++; i++;
      // ans;
      //printf ("begin: %d, end: %d: ", (i - j), i);
      //std::cout << a.substr (i - j, i - (i - j)) << '\n';
      if (ans.size () < (i - (i - j))) {
        ans = a.substr (i - j, i - (i - j));
        first = i-j;
      }
      else if (ans.size () == (i - (i - j)) && first > (i-j)) {
        ans = a.substr (i - j, i - (i - j));
        std::reverse (ans.begin (), ans.end ());
        first = i-j;
      }
    }
    else {
      if (j == 0)
        i++;
      else
        j = lps [j - 1];
    }
  }
}

int main () {
  std::cin >> a >> b;
  kmp ();
  std::reverse (a.begin (), a.end ());
  std::reverse (b.begin (), b.end ());
  kmp ();
  if (ans.size ())
    std::cout << ans << '\n';
  std::cout << ans.size () << '\n';
  return 0;
}
