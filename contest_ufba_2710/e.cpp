#include <bits/stdc++.h>

const int MAXN = (int)1e5;

std::bitset <(int)1e5> bs;
int f_xor [MAXN], b_xor [MAXN];

int main () {
  std::string str;
  std::cin >> str;
  int n = str.size ();

  
  f_xor [0] = str [0] - '0';
  for (int i = 1; i < n; i++) {
    f_xor [i] = f_xor [i - 1] ^ (str [i] - '0');
  }

  b_xor [n - 1] = str [n - 1] - '0';
  for (int i = n - 2; i >= 0; i--) {
    b_xor [i] = b_xor [i + 1] ^ (str [i] - '0');
  }

  if (n == 1) {
    if ('0' != str [0])
      puts ("NO");
    else
      puts ("YES");
    return 0;
  }

  /*
  for (int i = 0; i < n; i++)
    printf ("%d ", f_xor[i]);
  puts ("");

  for (int i = 0; i < n; i++)
    printf ("%d ", b_xor[i]);
  puts ("");
  */

  // n >= 2
  for (int i = n - 1; i >= 0; i--) {
    if (i == (n - 1)) {
      if (f_xor [i - 1] != (str [i] - '0')) {
        puts ("NO");
        return 0;
      }
    }
    else {
      int x = b_xor [i + 1];
      int y;
      if (i - 1 >= 0) {
        y = f_xor [i - 1];
      }
      else {
        y = 0;
      }

      if (x == y && (str [i] - '0') != 0) {
        puts ("NO");
        return 0;
      }
      else if (x != y && (str [i] - '0') != 1) {
        puts ("NO");
        return 0;
      }
    }
  }

  puts ("YES");

  return 0;
}
