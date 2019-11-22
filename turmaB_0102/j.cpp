#include <bits/stdc++.h>

/*
bool areParallel (line l1, line l2) {
  return (fabs (l1.a - l2.a) < EPS) && (fabs (l1.b - l2.b) < EPS);
}

bool areIntersect (line l1, line l2, point &p) {
  if (areParallel (l1, l2)) return false;

  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

  if (fabs (l1.b) > EPS)
    p.y = -(l1.a * p.x + l1.c);
  else
    p.y = -(l2.a * p.x + l2.c);

  return true;
}


line pointsToLine (point p1, point p2) {
  line l;
  if (fabs (p1.x - p2.x) < EPS) {
    l.a = 1.0; l.b = 0; l.c = -p1.x;
  }
  else {
    l.a = -(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1;
    l.c = -(l.a * p1.x) - p1.y;
  }

  return l;
}
*/

const long double EPS = 1e-13;
const int MAXN = 3e2 + 1;

struct point {
  long double x, y;
};

struct line {
  long double a, b, c;
};


point toVector (point a, point b) {
  point ans;
  ans.x = b.x - a.x;
  ans.y = b.y - a.y;
  return ans;
}

long double cross (point a, point b) {
  return a.x * b.y - a.y * b.x;
}

long double checkTurn (point a, point b, point c) {
  return cross (toVector (a, b), toVector (a, c)) > 0;
}

line arr [MAXN];

int main () {
  point h, u;
  scanf ("%Lf%Lf", &h.x, &h.y);
  scanf ("%Lf%Lf", &u.x, &u.y);

  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%Lf%Lf%Lf", &arr [i].a, &arr [i].b, &arr [i].c);

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    point left, right;
    if (arr [i].a) {
      left.y = -1e6;
      left.x = ((-arr [i].c) - (arr [i].b * left.y)) / arr [i].a;
      right.y = 1e6;
      right.x = ((-arr [i].c) - (arr [i].b * right.y)) / arr [i].a;
    }
    else {
      left.x = -1e6;
      left.y = ((-arr [i].c) - (arr [i].a * left.x)) / arr [i].b;
      right.x = 1e6;
      right.y = ((-arr [i].c) - (arr [i].a * right.x)) / arr [i].b;
    }

    if ((checkTurn (h, u, left) != checkTurn (h, u, right)) &&
        (checkTurn (left, right, h) != checkTurn (left, right, u)))
      ans++;
  }

  printf ("%lld\n", ans);

  return 0;
}
