#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;

typedef struct point {
	ld x, y;

	point () {}
	point (ld x, ld y) : x (x), y (y) {}

	point operator- (point& a) {
		return {x - a.x, y - a.y};
	}

	bool operator< (point& a) {
		if (x == a.x)
			return y < a.y;
		return x < a.x;
	}

	bool operator> (point& a) {
		if (x == a.x)
			return y > a.y;
		return x > a.x;
	}

	bool operator== (point &a) {
		return x == a.x && y == a.y;
	}

	bool operator>= (point &a) {
		if (x == a.x)
			return y > a.y || y == a.y;
		return x > a.x || x == a.x;
	}

	bool operator<= (point &a) {
		if (x == a.x)
			return y < a.y || y == a.y;
		return x < a.x || x == a.x;
	}

} point;

typedef struct segment {
	point a, b;

	segment () {}
	segment (point a, point b) : a (a), b (b) {}
} segment;

typedef struct line {
	ld a, b, c;

	line () {}
	line (ld a, ld b, ld c) : a (a), b (b), c (c) {}
} line;

line pointsToLine(point p1, point p2) {
	line l;
	if (fabs(p1.x-p2.x) < EPS)
		l = {1.0, 0.0, -p1.x};
	else {
		double a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
		l = {a , 1.0, -(double)(a*p1.x) - p1.y};
	}
	return l;
}


point to_vec (const point& a, const point& b) {
	return {a.x - b.x, a.y - b.y};
}

ld dot (point a, point b) {
	return a.x*b.x + a.y*b.y;
}

ld cross (point a, point b) {
	return a.x*b.y - a.y*b.x;
}

int check_turn (point a, point b, point c) {
  return cross (to_vec (a, b), to_vec (a, c)) > 0;
}

bool collinear(point p, point q, point r) {
  return cross(to_vec(p, q), to_vec(p, r)) == 0;
}

bool in_bouding_box(point p, point q, point r) {
  ld maxX = std::max(q.x, r.x), minX = std::min(q.x, r.x);
  ld maxY = std::max(q.y, r.y), minY = std::min(q.y, r.y);
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

bool areParallel(line l1, line l2) {       // check coefficients a & b
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool are_same(line l1, line l2) {           // also check coefficient c
	return areParallel(l1 ,l2) && (fabs(l1.c-l2.c) < EPS);
}

point line_intersect (line l1, line l2) {
	point p;
	p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
	if (fabs(l1.b) > EPS)
		p.y = -(l1.a*p.x + l1.c);
	else
		p.y = -(l2.a*p.x + l2.c);

	return p;
}

point arr [4];

void input () {
	for (int i = 0; i < 4; i++)
		scanf ("%Lf%Lf", &(arr + i)->x, &(arr + i)->y);

	solve ();
}

void solve () {
	if (segment_intersect ({arr [0], arr [1]}, {arr [2], arr [3]})) {
		line l1 = pointsToLine (arr [0], arr [1]);
		line l2 = pointsToLine (arr [2], arr [3]);
		//printf ("{%Lf, %Lf, %Lf}\n", l1.a, l1.b, l1.c);
		//printf ("{%Lf, %Lf, %Lf}\n", l2.a, l2.b, l2.c);
		if (are_same (l1, l2)) {
			std::sort (arr, arr + 2);
			std::sort (arr + 2, arr + 4);

			point a, b;

			if (arr [0] <= arr [2]) { // 0---2
				if (arr [1] <= arr [3]) { // 0---2--1--3
					a = arr [2];
					b = arr [1];
				}
				else { // 0---2--3--1
					a = arr [2];
					b = arr [3];
				}
			}
			else { // 2---0
				if (arr [1] >= arr [3]) { // 2---0--3--1
					a = arr [0];
					b = arr [3];
				}
				else { // 2---0--1--3
					a = arr [0];
					b = arr [1];
				}
			}

			if (a == b)
				printf ("%.10Lf %.10Lf\n", a.x, a.y);
			else {
				printf ("%.10Lf %.10Lf\n", a.x, a.y);
				printf ("%.10Lf %.10Lf\n", b.x, b.y);
			}
		}
		else {
			point p = line_intersect (l1, l2);
			printf ("%.10Lf %.10Lf\n", p.x, p.y);
		}
	}
	else
		puts ("Empty");
}

int main () {
	input ();
	return 0;
}
