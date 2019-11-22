#include <bits/stdc++.h>


void input ();
void solve ();

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9, inf = 1e18L;

struct point {
	ld x, y;
	point() { x = y = 0.0; }
	point(ld _x, ld _y) : x(_x), y(_y) {}
	ld norm() { return hypotl(x, y); }
	point normalized() {
		return point(x,y)*(1.0L/norm());
	}
	ld angle() { return atan2(y, x); }
	ld polarAngle() {
		ld a = atan2l(y, x);
		return a < 0 ? a + 2*acosl(-1.0L) : a;
	}
	bool operator < (point other) const {
		if (std::abs(x - other.x) > EPS) return x < other.x;
		else return y < other.y;
	}
	bool operator == (point other) const {
		return (std::abs(x - other.x) < EPS && (std::abs(y - other.y) < EPS));
	}
	point operator +(point other) const {
		return point(x + other.x, y + other.y);
	}
	point operator -(point other) const {
		return point(x - other.x, y - other.y);
	}
	point operator *(ld k) const {
		return point(x*k, y*k);
	}
};
ld dist(point p1, point p2) {
	return hypotl(p1.x - p2.x, p1.y - p2.y);
}
ld inner(point p1, point p2) {
	return p1.x*p2.x + p1.y*p2.y;
}
ld cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}
bool ccw(point p, point q, point r) {
	return cross(q-p, r-p) > 0;
}
bool collinear(point p, point q, point r) {
	return std::abs(cross(p-q, r-p)) < EPS;
}
point rotate(point p, ld rad) {
	return point(p.x * cosl(rad) - p.y * sinl(rad),
			p.x * sinl(rad) + p.y * cosl(rad));
}
ld angle(point a, point o, point b) {
	return acos(inner(a-o, b-o) / (dist(o,a)*dist(o,b)));
}
point proj(point u, point v) {
	return v*(inner(u,v)/inner(v,v));
}
bool between(point p, point q, point r) {
	return collinear(p, q, r) && inner(p - q, r - q) <= 0;
}
point lineIntersectSeg(point p, point q, point A, point B) {
	ld c = cross(A-B, p-q);
	ld a = cross(A, B);
	ld b = cross(p, q);
	return ((p-q)*(a/c)) - ((A-B)*(b/c));
}
bool parallel(point a, point b) {
	return std::abs(cross(a, b)) < EPS;
}
bool segIntersects(point a, point b, point p, point q) {
	if (parallel(a-b, p-q)) {
		return between(a, p, b) || between(a, q, b)
			|| between(p, a, q) || between(p, b, q); 
	}
	point i = lineIntersectSeg(a, b, p, q);
	return between(a, i, b) && between(p, i, q);
}


typedef struct line {
	ld a, b, c;

	line () {}
	line (ld a, ld b, ld c) : a (a), b (b), c (c) {}

	line to_line (point a, point b) const {
		if (a.x == b.x)
			return {1.0, 0.0, -(ld)a.x};
		else {
			ld t1 = -(ld)(a.y - b.y) / (a.x - b.x);
			ld t2 = -(ld)(t1 * a.x) - a.y;
			return {t1, 1.0, t2};
		}
	}
} line;

typedef std::vector <point> vp;

line l1, l2;
vp in;

bool parallel (line a, line b) {
	return (std::abs (a.a - b.a) < EPS) && (std::abs (a.b - b.b) < EPS);
}

bool are_same (line a, line b) {
	return parallel (a, b) && (std::abs (a.c - b.c) < EPS);
}

bool intersect (line a, line b) {
	return !parallel (a, b);
}

bool bt (point a, point b, point c) {
	return (a.x < c.x) && (b.x > c.x);
}

void input () {
	point p1, p2;
	scanf ("%Lf%Lf%Lf%Lf", &p1.x, &p1.y, &p2.x, &p2.y);
	if (p1.x != p2.x || p1.y != p2.y)
		l1 = l1.to_line (p1, p2);
	else {
		puts ("Empty");
		return;
	}
	in.push_back (p1);
	in.push_back (p2);
	scanf ("%Lf%Lf%Lf%Lf", &p1.x, &p1.y, &p2.x, &p2.y);
	if (p1.x != p2.x || p1.y != p2.y)
		l2 = l2.to_line (p1, p2);
	else {
		puts ("Empty");
		return;
	}
	in.push_back (p1);
	in.push_back (p2);
	solve ();
}

void solve () {
	/*
	   if (l1.are_same (l1, l2)) {
	   point p1 = std::min (in [0], in [1]);
	   point p2 = std::max (in [0], in [1]);
	   if (bt (p1, p2, in [2]) || bt (p1, p2, in [3])) {
	   std::sort (in.begin (), in.end ());
	   printf ("%Lf %Lf\n%Lf %Lf\n", in [1].x, in [1].y, in [2].x, in [2].y);
	   }
	   else
	   puts ("Empty");
	   }
	   else if (l1.intersect (l1, l2)) {
	   point p1 = std::min (in [0], in [1]);
	   point p2 = std::max (in [0], in [1]);
	   if (l1.are_same (l1, l2) && (bt (p1, p2, in [2]) || bt (p1, p2, in [3]))) {
	   std::sort (in.begin (), in.end ());
	   printf ("%Lf %Lf\n%Lf %Lf\n", in [1].x, in [1].y, in [2].x, in [2].y);
	   }
	   else {
	   point ans;
	   ans.x = ((l2.b * l1.c) - (l1.b * l2.c)) / ((l2.a * l1.b) - (l1.a * l2.b));
	   if (std::abs (l1.b) > EPS)
	   ans.y = -((l1.a * ans.x) + l1.c);
	   else
	   ans.y = -((l1.a * ans.x) + l2.c);

	   printf ("%Lf %Lf\n", ans.x, ans.y);
	   }
	   }
	   else
	   puts ("Empty");
	   */
	if (segIntersects (in [0], in [1], in [2], in [3])) {
		if (!are_same (l1, l2)) {
			point ans;
			ans.x = ((l2.b * l1.c) - (l1.b * l2.c)) / ((l2.a * l1.b) - (l1.a * l2.b));
			if (std::abs (l1.b) > EPS)
				ans.y = -((l1.a * ans.x) + l1.c);
			else
				ans.y = -((l2.a * ans.x) + l2.c);

			printf ("%.20Lf %.20Lf\n", ans.x, ans.y);
		}
		else {
			std::sort (in.begin (), in.end ());
			printf ("%.20Lf %.20Lf\n%.20Lf %.20Lf\n", in [1].x, in [1].y, in [2].x, in [2].y);
		}
	}
	else
		puts ("Empty");
}

int main () {
	input ();
	return 0;
}
