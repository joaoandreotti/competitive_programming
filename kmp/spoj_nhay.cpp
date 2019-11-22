#include <bits/stdc++.h>

const int MAXP = 1e5; // max pattern size

int lps [MAXP]; // suffix which is a prefix
int flag;

void build_lps (std::string a) { // a == pattern
  int i = 1, j = 0;
  lps [0] = 0;

  while (i < a.size ()) {
    if (a[i] == a [j]) { // match
      j++;
      lps [i++] = j;
    }
    else { // missmatch
      // if j == 0 cant go back anymore
      // so lps [i] doesnt belongs to a suffix
      // which is a prefix
      // else => can go back so there's still chance
      if (j == 0)
        lps [i++] = 0;
      else
        j = lps [j - 1];
    }
  }
}

void kmp_search (std::string a, std::string b) { // a == text, b == pattern
  int i = 0, j = 0;
  build_lps (b);

  /*
  printf ("%d, %d\n", (int)a.size (), (int)b.size ());
  puts ("lps:");
  for (int i = 0; i < b.size (); i++)
    printf ("%d ", lps [i]);
  puts ("");
  */

  while (i < (int)a.size ()) { // until text.size - pattern.size
    if (a [i] == b [j]) { //match
      i++; j++;
      if (j == (int)b.size ()) { // pattern match
        printf ("%d\n", i - j);
        j = lps [j - 1];
        flag = 1;
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
  int n;
  while (scanf ("%d", &n) != EOF) {
    std::string a, b;
    std::cin >> b >> a;
    flag = 0;

    memset (lps, 0, (int)b.size () * 4);
    kmp_search (a, b);

    if (!flag)
      puts ("");
  }
  return 0;
}
