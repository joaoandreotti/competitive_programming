#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 1e5 + 1;

int n;
int events [MAXN];

void input () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", events + i);
  solve ();
}

void solve () {
  std::set <int> vis, crr;
  std::vector <int> ans;
  int count = 0;
  int e = 0;
  int flag = 0;

  for (int i = 0; i < n; i++) {
    if (events [i] > 0) {
      auto x = vis.find (events [i]);
      e++;
      if (x == vis.end ()) {
        crr.insert (events [i]);
        vis.insert (events [i]);
      }
      else {
        flag = 1;
      }
    }
    if (events [i] < 0) {
      auto x = crr.find (-events [i]);
      e++;
      if (x != crr.end ())
        crr.erase (x);
      else {
        flag = 1;
      }
    }

    if (crr.empty ()) {
      count++;
      ans.push_back (e);
      e = 0;
      vis.clear ();
    }
  }

  if (flag || !crr.empty ())
    puts ("-1");
  else {
    printf ("%d\n", count);
    for (int i = 0; i < ans.size (); i++)
      if (i + 1 < ans.size ())
        printf ("%d ", ans [i]);
      else
        printf ("%d\n", ans [i]);
  }
}

int main () {
  input ();
  return 0;
}
