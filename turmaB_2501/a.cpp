#include <bits/stdc++.h>

#define x first
#define y second

typedef std::pair <int, int> pi;
typedef std::vector <pi> vp;
typedef std::set <pi> sp;
int n;
vp arr;
sp set;

int cross (pi a, pi b) {
  return a.x * b.y - a.y * b.x;
}

pi toVector (pi a, pi b) {
  pi ans;
  ans.x = b.x - a.x;
  ans.y = b.y - a.y;
  return ans;
}

int checkTurn (pi a, pi b, pi c) {
  return cross (toVector (a, b), toVector (a, c));
}

vp ch_monotone (vp pts) {
  int k = 0;
  vp ans (pts.size () * 2);
  std::sort (pts.begin (), pts.end ());

  // lower hull
  for (int i = 0; i < pts.size (); i++) {
    // more than 2 points and while notConvex remove last point
    while (k >= 2 && checkTurn (ans [k - 2], ans [k - 1], pts [i]) < 0) {
      k--;
    }
    ans [k++] = pts [i];
  }
  // upper hull
  for (int i = (int)pts.size () - 2, t = k + 1; i >= 0; i--) {
    // k >= t to not erase the lower hull ans while notConvex remove last point
    while (k >= t && checkTurn (ans [k - 2], ans [k - 1], pts [i]) < 0)
      k--;
    ans [k++] = pts [i];
  }

  ans.resize (k);
  return ans;
}

int main () {
  int x, y;
  while (scanf ("%d", &n) && n) {
    arr.clear ();
    set.clear ();
    for (int i = 0; i < n; i++) {
      scanf ("%d%d", &x, &y);
      arr.push_back ({x, y});
      set.insert ({x, y});
    }
    long long count = 0;
    while (!set.empty ()) {
      vp hull = ch_monotone (arr);
      for (int i = 0; i < hull.size (); i++)
        set.erase (hull [i]);
      arr.clear ();
      for (auto i = set.begin (); i != set.end (); i++)
        arr.push_back (*i);
      count++;
    }
    if (count % 2)
      puts ("Take this onion to the lab!");
    else
      puts ("Do not take this onion to the lab!");
  }
  return 0;
}
