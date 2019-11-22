#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stack>

int main () {
  int n;
  scanf ("%d", &n);

  for (int count = 0; count < n; count++) {
    int n1, n2, d1, d2;
    char ch1, ch2, ch3;
    scanf ("%d %c %d %c %d %c %d", &n1, &ch1, &d1, &ch2, &n2, &ch3, &d2);
    if (ch2 == '+') {
      int num = (int)(n1) * (int)(d2);
      num += (int)(n2) * (int)(d1);
      int den = (int)(d1) * (int)(d2);
      int x, y;
      x = num; y = den;
      printf ("%d/%d =", num, den);

      for (int i = 2; i < std::max (x, y);) {
        if (num % i == 0 && den % i == 0) {
          num /= i;
          den /= i;
        }
        else {
          i++;
        }
      }
      printf (" %d/%d\n", num, den);
    }
    if (ch2 == '-') {
      int num = (int)(n1) * (int)(d2);
      num -= (int)(n2) * (int)(d1);
      int den = (int)(d1) * (int)(d2);
      int x, y;
      x = num; y = den;
      printf ("%d/%d =", num, den);

      for (int i = 2; i < std::max (x, y);) {
        if (num % i == 0 && den % i == 0) {
          num /= i;
          den /= i;
        }
        else {
          i++;
        }
      }
      printf (" %d/%d\n", num, den);
    }
    if (ch2 == '*') {
      int num = (int)(n1) * (int)(n2);
      int den = (int)(d1) * (int)(d2);
      int x, y;
      x = num; y = den;
      printf ("%d/%d =", num, den);

      for (int i = 2; i < std::max (x, y);) {
        if (num % i == 0 && den % i == 0) {
          num /= i;
          den /= i;
        }
        else {
          i++;
        }
      }
      printf (" %d/%d\n", num, den);
    }
    if (ch2 == '/') {
      int num = (int)(n1) * (int)(d2);
      int den = (int)(n2) * (int)(d1);
      int x, y;
      x = num; y = den;
      printf ("%d/%d =", num, den);

      for (int i = 2; i < std::max (x, y);) {
        if (num % i == 0 && den % i == 0) {
          num /= i;
          den /= i;
        }
        else {
          i++;
        }
      }
      printf (" %d/%d\n", num, den);
    }
  }
  return 0;
}
