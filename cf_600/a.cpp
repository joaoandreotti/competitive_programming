#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

int t, n;
int arr [MAXN], brr [MAXN], crr [MAXN];

void input () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);

    for (int i = 0; i < n; i++)
      scanf ("%d", arr + i);

    for (int i = 0; i < n; i++)
      scanf ("%d", brr + i);

    solve ();
  }
}

void solve () {
  int flag = 0, flag1 = 1;
  for (int i = 0; i < n; i++) {
    crr [i] = brr [i] - arr [i];
    if (crr [i] < 0)
      flag = 1;

    if (crr [i] == 0)
      flag1 = 0;
  }

  int changes = 0;
  int last = 0;
  int flag2 = 0;
  for (int i = 0; i < n - 1; i++) {
    if (crr [i] != crr [i + 1]) {
      changes++;

      if (changes > 1 && last != arr [i + 1])
        flag2 = 1;
    }

    if (changes == 1)
      last = crr [i];
  }


  if (flag)
    puts ("NO");
  else {

    //printf ("{%d, %d, %d}\n", changes, last, flag);

    if (changes == 0) {
      puts ("YES");
      return;
    }

    if (flag1)
      puts ("NO");
    else if (changes <= 1)
      puts ("YES");
    else
      if (flag2)
        puts ("NO");
      else if (changes > 2)
        puts ("NO");
      else
        puts ("YES");

  }


}

int main () {
  input ();
  return 0;
}
