#include <bits/stdc++.h>

const int MAXP = 100; // max pattern size

int lsp [MAXP]; // suffix which is a prefix

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
  int i = 0; j = 0;
  build_lps (b);

  while (i < a.size () - b.size ()) { // until text.size - pattern.size
    if (a [i] == b [j]) { //match
      i++; j++;
      if (j == b.size ()) { // pattern match
        j = lps [j - 1];
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
  return 0;
}
