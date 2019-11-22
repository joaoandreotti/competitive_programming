#include <bits/stdc++.h>

void input ();
void sol ();

const int MAXN = 1e4 + 10;

int n;
int arr [MAXN];

void input () {
  while (scanf ("%d", &n) && n) {
    for (int i = 0; i < n; i++)
      scanf ("%d", arr + i);
    sol ();
  }
}

void sol () {
  long long crr = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    crr += arr [i];
    ans = std::max (ans, crr);
    if (crr < 0) crr = 0;
  }
  if (ans)
    printf ("The maximum winning streak is %lld.\n", ans);
  else
    puts ("Losing streak.");
}

int main () {
  input ();
  return 0;
}
