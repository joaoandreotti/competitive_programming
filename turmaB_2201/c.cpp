#include <bits/stdc++.h>
// RUNTIME FUCKING ERROR -- CODIGO RUIM

struct point {
  long long x = 0, y = 0;
  long long side, size;

  point () {}

  point (long long x, long long y, long long sd, long long sz) : x (x), y (y), side (sd), size (sz) {}

  point operator- (point a) {
    point ans;
    ans.x = x - a.x;
    ans.y = y - a.y;
    ans.side = a.side;
    return ans;
  }

  // lexographically
  bool operator< (point a) {
    if (x == a.x)
      return y < a.y;
    return x < a.x;
  }
};

int quarter (point a) {
  if (a.x >= 0 && a.y >= 0)
    return 1;
  if (a.x <= 0 && a.y >= 0)
    return 2;
  if (a.x <= 0 && a.y <= 0)
    return 3;
  return 4;
}

long long cross (point a, point b) {
  return a.x * b.y - a.y * b.x;
}

point center;
bool cmp (point a, point b) {
  a = a - center; b = b - center; // relative points from a pivot
  if (quarter (a) == quarter (b)) {
    if (!cross (a, b)) {
      if ((a.y >= 0 && !a.side) || (a.y <= 0 && a.side))
        return 1;
      else
        return 0;
    }
    return cross (a, b) > 0;
  }

  return quarter (a) < quarter (b);
}

typedef std::vector <point> vp;
vp arr, rel_arr;
long long ans = 0, aux;
int n;

int main () {
  while (scanf ("%d", &n) != EOF) {
    arr.clear ();
    rel_arr.clear ();
    ans = 0;
    for (int i = 0; i < n; i++) {
      int a, b, c; scanf ("%d%d%d", &a, &b, &c);
      if (a > b)
        std::swap (a, b);
      arr.push_back (point (a, c, 0, abs (b - a)));
      arr.push_back (point (b, c, 1, abs (b - a)));
    }

    for (int i = 0; i < arr.size (); i++) {
      center = arr [i];
      rel_arr = arr;
      std::stable_sort (rel_arr.begin (), rel_arr.end (), cmp);
      aux = center.size;
      for (int j = 0; j < rel_arr.size (); j++) {
        if (rel_arr [i].y < center.y) {
          rel_arr [i].x = -rel_arr [i].x;
          rel_arr [i].y = -rel_arr [i].y;
        }
      }

      //printf ("center: {%d, %d, %d, %d}\n", center.x, center.y, center.side, center.size);
      for (int j = 0; j < rel_arr.size (); j++) {
        //printf ("aux: %d\n", aux);
        if (center.y != rel_arr [j].y) {
          //printf ("rel_arr [j]: {%d, %d, %d, %d} => ", rel_arr [j].x, rel_arr [j].y, rel_arr [j].side, rel_arr [j].size);
          if (rel_arr [j].y > center.y) {
            if (rel_arr [j].side) {
              //puts ("entrou");
              aux += rel_arr [j].size;
            }
            else {
              //puts ("saiu");
              aux -= rel_arr [j].size;
            }
          }
          else {
            if (rel_arr [j].side) {
              //puts ("saiu");
              aux -= rel_arr [j].size;
            }
            else {
              //puts ("entrou");
              aux += rel_arr [j].size;
            }
          }
          ans = std::max (ans, aux);
        }
      }
      //puts ("-------");
    }
    printf ("%lld\n", ans);
  }
  return 0;
}
