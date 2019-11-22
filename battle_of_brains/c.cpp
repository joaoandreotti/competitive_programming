#include <bits/stdc++.h>

void input ();
void solve ();

typedef long double ld;

const ld PI = acosl (-1);

int t, cs;
ld r;

void input () {
  scanf ("%d", &t);
  for (cs = 1; cs <= t; cs++) {
    scanf ("%Lf", &r);
    solve ();
  }
}

void solve () {
  ld Aafd, Haed, Aafe, Aahf, Aagf;

  Haed = hypotl (r, r);
  Aafd = (PI * ((Haed / 2.0) * (Haed / 2.0))) / 4.0;
  Aafe = ((Haed / 2.0) * (Haed / 2.0)) / 2.0;
  Aahf = Aafd - Aafe;

  Aagf = (PI * powl (r / 2.0, 2)) / 2;

  //printf ("Haed %Lf, Aafd %Lf, Aafe %Lf, Aahf %Lf, Aagf %Lf\n", Haed, Aafd, Aafe, Aahf, Aagf);

  ld ans = Aagf - Aahf;

  printf ("Case %d: %.4Lf\n", cs, ans);
}

int main () {
  input ();
  return 0;
}
