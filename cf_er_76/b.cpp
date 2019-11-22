#include <bits/stdc++.h>

void input ();
void solve ();

int t;
long long a, b;

void input () {
  scanf ("%d", &t);
  for (int cs = 0; cs < t; cs++) {
    scanf ("%lld%lld", &a, &b);
    solve ();
  }
}

void solve () {
  if (a <= 3) {
    if (a == 1 && b != a)
      puts ("NO");
    else if (b > 3)
      puts ("NO");
    else
      puts ("YES");
  }
  else
    puts ("YES");
}

int main () {
  input ();
  return 0;
}
