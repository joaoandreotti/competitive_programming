#include <bits/stdc++.h>

struct Point {
  int x = 0, y = 0;

  Point operator- (Point a) {
    Point ans;
    ans.x = x - a.x;
    ans.y = y - a.y;
    return ans;
  }

  // lexographically
  bool operator< (Point a) {
    if (x == a.x)
      return y < a.y;
    return x < a.x;
  }
};

Point center;

// which quarter
int quarter (Point a) {
  if (a.x >= 0 && a.y >= 0)
    return 1;
  if (a.x <= 0 && a.y >= 0)
    return 2;
  if (a.x <= 0 && a.y <= 0)
    return 3;
  return 4;
}

// cros product
int cross (Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}

// return a point which represents a vector
Point toVector (Point a, Point b) {
  Point ans;
  ans.x = b.x - a.x;
  ans.y = b.y - a.y;
  return ans;
}

// positive == left, 0 == colinear, negative == right
int checkTurn (Point a, Point b, Point c) {
  return cross (toVector (a, b), toVector (a, c));
}

// compare function by polar angle
bool cmp (Point a, Point b) {
  a = a - center; b = b - center; // relative points from a pivot
  if (quarter (a) == quarter (b))
    return cross (a, b) > 0;

  return quarter (a) < quarter (b);
}

// convex hull Andrew`s monotone chain
std::vector <Point> ch_monotone (std::vector <Point> pts) {
  int k = 0;
  std::vector <Point> ans (pts.size () * 2);
  std::sort (pts.begin (), pts.end ());

  puts ("SORTED:");
  for (int i = 0; i < pts.size (); i++)
    printf ("{%d, %d} ", pts [i].x, pts [i].y);
  puts ("");

  // lower hull
  for (int i = 0; i < pts.size (); i++) {

    // more than 2 points and while notConvex remove last point
    while (k >= 2 && checkTurn (ans [k - 2], ans [k - 1], pts [i]) < 0)
      k--;
    ans [k++] = pts [i];
  }
  printf ("k: %d\n", k);
  for (int i = 0; i < k; i++)
    printf ("{%d, %d} ", ans [i].x, ans [i].y);
  puts ("");
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
  std::vector <Point> input, hull;

  input.resize (7);
  input [0].x = 0; input [0].y = 0;
  input [1].x = 0; input [1].y = 8;
  input [2].x = 1; input [2].y = 6;
  input [3].x = 3; input [3].y = 1;
  input [4].x = 6; input [4].y = 6;
  input [5].x = 8; input [5].y = 0;
  input [6].x = 8; input [6].y = 8;

  puts ("INPUT:");
  for (int i = 0; i < input.size (); i++)
    printf ("{%d, %d} ", input [i].x, input [i].y);
  puts ("");

  hull = ch_monotone (input);

  puts ("CH:");
  for (int i = 0; i < hull.size (); i++)
    printf ("{%d, %d} ", hull [i].x, hull [i].y);
  puts ("");

  return 0;
}
