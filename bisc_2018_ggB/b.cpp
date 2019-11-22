#include <bits/stdc++.h>

void input ();
void solve ();

typedef long double ld;
typedef long long ll;

typedef struct point {
	ld x, y;

	point () {}
	point (ld x, ld y) : x (x), y (y) {}

	point operator- (point& a) {
		return {x - a.x, y - a.y};
	}

} point;

typedef struct line {
	ld a, b, c;
} line;

typedef struct segment {
	point a, b;

	segment () {}
	segment (point a, point b) : a (a), b (b) {}
} segment;

point to_vec (const point& a, const point& b) {
	return {a.x - b.x, a.y - b.y};
}

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

line pointsToLine(point p1, point p2) {
	ll a = p1.y - p2.y;
	ll b = p1.x - p2.x;
	ll c = p1.y * p2.x - p2.y * p1.x;

	ll d = gcd(gcd(a, b), c);
	a/=d, b/=d, c/=d;

	if (a < 0) a*=-1, b*=-1, c*=-1;

	return {(ld)a, (ld)b, (ld)c};
}

ld dot (point a, point b) {
	return a.x*b.x + a.y*b.y;
}

ld cross (point a, point b) {
	return a.x*b.y - a.y*b.x;
}

ld dist (point a, point b) {
	return hypotl (b.x - a.x, b.y - a.y);
}

ld t_area (point a, point b, point c) {
	ld area = 0;

	area += a.x * b.y;
	area -= a.y * b.x;

	area += b.x * c.y;
	area -= b.y * c.x;

	area += c.x * a.y;
	area -= c.y * a.x;

	return std::abs (area) / 2;
}

ld dist_seg (point a, point b, point c) {
	ld tans = (t_area (a, b, c) * 2) / dist (b, c);
	ld ta = dist (a, b);
	ld tb = dist (a, c);

	ld da = dot (to_vec (b, c), to_vec (b, a));
	ld db = dot (to_vec (c, b), to_vec (c, a));
	
	if (!(da >= 0 && db >= 0))
		return std::min ({ta, tb});

	return tans;
}

ld dist_hir (point a, point b, point c) {
	ld tans = (t_area (a, b, c) * 2) / dist (b, c);

	ld ta = dist (a, b);
	ld da = dot (to_vec (b, a), to_vec (b, c));

	if (da <= 0)
		return ta;

	return tans;
}

ld dist_line (point a, point b, point c) {
	ld tans = (t_area (a, b, c) * 2) / dist (b, c);
	return tans;
}

int check_turn (point a, point b, point c) {
  return cross (to_vec (a, b), to_vec (a, c)) > 0;
}

bool collinear(point p, point q, point r) {
  return cross(to_vec(p, q), to_vec(p, r)) == 0;
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

  if (check_turn(s.a, s.b, t.a) != check_turn(s.a, s.b, t.b) 
      && check_turn(t.a, t.b, s.a) != check_turn(t.a, t.b, s.b))
    return true;

  return false;
}

point arr [4];

void input () {
	for (int i = 0; i < 4; i++)
		scanf ("%Lf%Lf", &(arr + i)->x, &(arr + i)->y);

	solve ();
}

void solve () {
	//part-1
	
	// dist A-C
	printf ("%.10Lf\n", dist (arr [0], arr [2]));

	// distance from A to segment CD
	// 2 * A / b
	printf ("%.10Lf\n", dist_seg (arr [0], arr [2], arr [3]));

	// distance from A to half-infinity ray CD
	printf ("%.10Lf\n", dist_hir (arr [0], arr [2], arr [3]));

	// distance from A to line CD
	printf ("%.10Lf\n", dist_line (arr [0], arr [2], arr [3]));


	// part-2
	
	// dist C to segment AB
	printf ("%.10Lf\n", dist_seg (arr [2], arr [0], arr [1]));

	// dist segment AB to segment CD
	if (segment_intersect ({arr [0], arr [1]}, {arr [2], arr [3]}))
		puts ("0");
	else {
		// possivel WA
		ld a = dist_seg (arr [0], arr [2], arr [3]);
		ld b = dist_seg (arr [1], arr [2], arr [3]);
		printf ("%.10Lf\n", std::min (a, b));
	}

	// dist segment AB to hir CD
}

int main () {
	input ();
	return 0;
}
