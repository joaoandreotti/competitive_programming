struct point {int x, y;};
struct segment {point a, b;};

point tovec(point a, point b) {
  return {b.x-a.x, b.y-a.y};
}

int cross(point a, point b) {
  return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q, point r) {
  return cross(tovec(p, q), tovec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
  return cross(tovec(p, q), tovec(p, r)) == 0;
}

bool in_bouding_box(point p, point q, point r) {
  int maxX = std::max(q.x, r.x), minX = std::min(q.x, r.x);
  int maxY = std::max(q.y, r.y), minY = std::min(q.y, r.y);
  return p.x <= maxX && p.x >= minX && p.y <= maxY && p.y >= minY;
}

bool segment_intersect(segment s, segment t) {
  if (collinear(s.a, t.a, t.b) && in_bouding_box(s.a, t.a, t.b)) return true;
  if (collinear(s.b, t.a, t.b) && in_bouding_box(s.b, t.a, t.b)) return true;
  if (collinear(t.a, s.a, s.b) && in_bouding_box(t.a, s.a, s.b)) return true;
  if (collinear(t.b, s.a, s.b) && in_bouding_box(t.b, s.a, s.b)) return true;

  if (ccw(s.a, s.b, t.a) != ccw(s.a, s.b, t.b) 
      && ccw(t.a, t.b, s.a) != ccw(t.a, t.b, s.b))
  {
    return true;
  }

  return false;
}

