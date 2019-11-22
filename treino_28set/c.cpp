#include <bits/stdc++.h>

void input ();
void solve ();

const double EPS = 1e-9;

typedef struct point {
  double x, y;

  point () {
    x = y = 0.0;
  }

  point (double x, double y) : x (x), y (y) {}

  point operator - (point other) const {
    return point (x - other.x, y - other.y);
  }

  bool operator == (point other) const {
    return (fabs (x - other.x) < EPS && (fabs (y - other.y) < EPS));
  }

} point;

point pivot (0, 0);

typedef std::vector <point> polygon;

double cross (point p1, point p2) {
  return p1.x * p2.y - p1.y * p2.x;
}

bool collinear (point p, point q, point r) {
  return fabs (cross (p - q, r - p)) < EPS;
}

bool ccw (point p, point q, point r) {
  return cross (q - p, r - p) > 0;
}

double dist (point p1, point p2) {
  return hypot (p1.x - p2.x, p1.y - p2.y);
}

double inner (point p1, point p2) {
  return p1.x * p2.x + p1.y * p2.y;
}

double angle (point a, point o, point b) {
  return acos (inner (a - o, b - o) / (dist (o, a) * dist (o, b)));
}

bool between (point p, point q, point r) {
  return collinear (p, q, r) && inner (p - q, r - q);
}

bool ang_cmp (point a, point b) {
  if (collinear (pivot, a, b))
    return inner (pivot - a, pivot - a) < inner (pivot - b, pivot - b);

  return cross (a - pivot, b - pivot) >= 0;
}

point lineIntersectSeg (point p, point q, point A, point B) {
  double c = cross (A - B, p - q);
  double a = cross (A, B);
  double b = cross (p, q);

  return ((p - q) * (a / c)) - ((A - B) * (b / c));
}

bool in_pol (polygon & P, point p) {
  if (P.size () == 0u) return false;
  double sum = 0;

  int n = P.size ();

  for (int i = 0; i < n; i++) {
    if (P [i] == p || between (P [i], p, P [(i + 1) % n]))
      return true;
    if (ccw (p, P [i], P [(i + 1) % n]))
      sum += angle (P [i], p, P [(i + 1) % n]);
  }

  return fabs (fabs (sum) - 2 * acos (-1.0)) < EPS;
}


polygon intersect (polygon & A, polygon & B) {
  polygon P;

  int n = A.size (), m = B.size ();

  for (int i = 0; i < n; i++) {
    if (in_pol (B, A [i]))
      P.push_back (A [i]);

    for (int j = 0; j < m; j++) {
      point a1 = A [(i + 1) % n], a2 = A [i];
      point b1 = B [(j + 1) % n], b2 = B [j];

      if (parallel (a1 - a2, b1 - b2))
        continue;

      point q = lineIntersectSeg (a1, a2, b1, b2);

      if (!between (a1, q, a2))
        continue;
      if (!between (b1, q, b2))
        continue;
    }
  }

  for (int i = 0; i < m; i++)
    if (in_pol (A, B [i]))
      P.push_back (B [i]);

  //std::set <point> inuse;
  int sz = 0;

  for (int i = 0; i < (int)P.size (); i++) {
    if (inuse.count (P [i]))
      continue;
    inuse.insert (P [i]);

    P [sz++] = P [i];
  }

  P.resize (sz);

  if (!P.empty ()) {
    pivot = P [0];
    sort (P.begin (), P.end (), ang_cmp);
  }

  return P;
}


polygon pl1, pl2, pl3;

void input () {
  double a, b, c, d;

  scanf ("%lf%lf%lf%lf", &a, &b, &c, &d);
  pl1.push_back (point (a, b));
  pl1.push_back (point (c, d));
  pl1.push_back (point (a + c, b));
  pl1.push_back (point (a, b + d));

  scanf ("%lf%lf%lf%lf", &a, &b, &c, &d);
  pl2.push_back (point (a, b));
  pl2.push_back (point (c, d));
  pl2.push_back (point (a + c, b));
  pl2.push_back (point (a, b + d));

  scanf ("%lf%lf%lf%lf", &a, &b, &c, &d);
  pl3.push_back (point (a, b));
  pl3.push_back (point (c, d));
  pl3.push_back (point (a + c, b));
  pl3.push_back (point (a, b + d));
  
  solve ();
}

void solve () {
}

int main () {
  return 0;
}
