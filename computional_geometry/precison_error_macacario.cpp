#include <bits/stdc++.h>

#define EPS 1e-12

void input ();
void solve ();

typedef long long ll;
typedef long double ld;
typedef std::vector <ld> vld;


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
point closestToLineSegment(point p, point a, point b) {
	ld u = inner(p-a, b-a) / inner(b-a, b-a);
	if (u < 0.0) return a;
	if (u > 1.0) return b;
	return a + ((b-a)*u);
}
struct circle{
	point c;
	ld r;
	circle() { c = point(); r = 0; }
	circle(point _c, ld _r) : c(_c), r(_r) {}
	ld area() { return acos(-1.0)*r*r; }
	ld chord(ld rad) { return  2*r*sinl(rad/2.0); }
	ld sector(ld rad) { return 0.5*rad*area()/acosl(-1.0); }
	int intersects(circle other) {
		if (dist(c, other.c) > r + other.r)
			return 0;
		if (dist(c, other.c) < std::abs (r - other.r))
			return 0;
		else return 1;
	}
	bool contains(point p) { return dist(c, p) <= r + EPS; }
	std::pair<point, point> getTangentPoint(point p) {
		ld d1 = dist(p, c), theta = asinl(r/d1);
		point p1 = rotate(c-p,-theta);
		point p2 = rotate(c-p,theta);
		p1 = p1*(sqrtl(d1*d1-r*r)/d1)+p;
		p2 = p2*(sqrtl(d1*d1-r*r)/d1)+p;
		return std::make_pair(p1,p2);
	}
	std::vector< std::pair<point,point> > getTangentSegs(circle other) {
		std::vector<std::pair<point, point> > ans;
		ld d = dist(other.c, c);
		ld dr = std::abs(r - other.r), sr = r + other.r;
		if (dr >= d) return ans;
		ld u = acosl(dr / d);
		point dc1 = ((other.c - c).normalized())*r;
		point dc2 = ((other.c - c).normalized())*other.r;
		ans.push_back(std::make_pair(c + rotate(dc1, u), other.c + rotate(dc2, u)));
		ans.push_back(std::make_pair(c + rotate(dc1, -u), other.c + rotate(dc2, -u)));
		if (sr >= d) return ans;
		ld v = acos(sr / d);
		dc2 = ((c - other.c).normalized()) * other.r;
		ans.push_back({c + rotate(dc1, v), other.c + rotate(dc2, v)});
		ans.push_back({c + rotate(dc1, -v), other.c + rotate(dc2, -v)});
		return ans;
	}
	std::pair<point, point> getIntersectionPoints(circle other){
		assert(intersects(other));
		ld d = dist(c, other.c);
		ld u = acosl((other.r*other.r + d*d - r*r) / (2*other.r*d));
		point dc = ((other.c - c).normalized()) * r;
		return std::make_pair(c + rotate(dc, u), c + rotate(dc, -u));
	}
};

circle circumcircle(point a, point b, point c) {
	circle ans;
	point u = point((b-a).y, -(b-a).x);
	point v = point((c-a).y, -(c-a).x);
	point n = (c-b)*0.5;
	ld t = cross(u,n)/cross(v,u);
	ans.c = ((a+c)*0.5) + (v*t);
	ans.r = dist(ans.c, a);
	return ans;
}

int insideCircle(point p, circle c) {
	if (std::abs(dist(p , c.c) - c.r)<EPS) return 1;
	else if (dist(p , c.c) < c.r) return 0;
	else return 2;
} //0 = inside/1 = border/2 = outside

circle incircle( point p1, point p2, point p3 ) {
	ld m1=dist(p2, p3);
	ld m2=dist(p1, p3);
	ld m3=dist(p1, p2);
	point c = (p1*m1+p2*m2+p3*m3)*(1/(m1+m2+m3));
	ld s = 0.5*(m1+m2+m3);
	ld r = sqrt(s*(s-m1)*(s-m2)*(s-m3))/s;
	return circle(c, r);
}

int n;
int flag;
circle one, two;

void input () {
	scanf ("%d", &n);
	srand (time (0));
	for (int i = 0; i < n; i++) {
		one.c.x = rand () % (2001) - 1000;
		one.c.y = rand () % (2001) - 1000;
		one.r = rand () % (1001);
		two.c.x = rand () % (2001) - 1000;
		two.c.y = rand () % (2001) - 1000;
		two.r = rand () % (1001);

		printf ("%Lf %Lf %Lf\n", one.c.x, one.c.y, one.r);
		printf ("%Lf %Lf %Lf\n", two.c.x, two.c.y, two.r);
		//scanf ("%Lf%Lf%Lf", &one.c.x, &one.c.y, &one.r);
		//scanf ("%Lf%Lf%Lf", &two.c.x, &two.c.y, &two.r);
		solve ();
	}
}

void solve () {
	if (one.c.x == two.c.x && one.c.y == two.c.y && one.r == two.r)
		puts ("Oops, too many points");
	else if (one.intersects (two)) {
		point t1 = one.getIntersectionPoints (two).first;
		point t2 = one.getIntersectionPoints (two).second;

		if (t1 == t2) {
			puts ("There are only 1 of them");
			printf ("%.12Lf %.12Lf\n", t1.x, t1.y);
		}
		else {
			puts ("There are only 2 of them");
			printf ("%.12Lf %.12Lf\n", std::min (t1, t2).x, std::min (t1, t2).y);
			printf ("%.12Lf %.12Lf\n", std::max (t1, t2).x, std::max (t1, t2).y);
		}
	}
	else
		puts ("There are no points");
	puts ("");
}

int main () {
	input ();
	return 0;
}
