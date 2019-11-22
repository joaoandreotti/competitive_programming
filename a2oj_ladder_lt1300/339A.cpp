#include <bits/stdc++.h>

int main () {
  std::string str;
  std::cin >> str;
  int arr[(int)ceil (str.size () / 2.0)];
  int pos = 0;
  for (int i = 0; i < str.size (); i++) {
    if (str[i] != '+')
      arr[pos++] = str[i] - '0';
  }
  std::sort (arr, arr + pos);

  for (int i = 0; i < pos - 1; i++)
    printf ("%d+", arr[i]);
  printf ("%d\n", arr[pos-1]);

  return 0;
}
