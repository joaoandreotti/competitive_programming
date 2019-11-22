#include <bits/stdc++.h>

void input ();
void solve ();

typedef long long ll;
typedef long double ld;

typedef struct point {
  ll x = 0, y = 0;

  point () {}
  point (ll x, ll y) : x (x), y (y) {}

  // lexographically
  bool operator< (point a) {
	  if (x == a.x)
		  return y < a.y;
	  return x < a.x;
  }

  bool operator == (point a) {
	  return x == a.x && y == a.y;
  }
} point;

int quarter (point a) {
  if (a.x >= 0 && a.y >= 0)
    return 1;
  if (a.x <= 0 && a.y >= 0)
    return 2;
  if (a.x <= 0 && a.y <= 0)
    return 3;
  return 4;
}

point toVector (point a, point b) {
  point ans;
  ans.x = b.x - a.x;
  ans.y = b.y - a.y;
  return ans;
}

ld dst (point a, point b) {
	point c = toVector (a, b);
	return hypotl (c.x, c.y);
}

int cross (point a, point b) {
  return a.x * b.y - a.y * b.x;
}

int checkTurn (point a, point b, point c) {
  return cross (toVector (a, b), toVector (a, c));
}

typedef std::pair <ll, ll> pl;
typedef std::map <pl, int> mpi;
typedef std::pair <point, int> ppi;
typedef std::vector <ppi> vppi;
typedef std::vector <point> vp;

bool cmp (ppi a, ppi b) {
	  if (a.first.x == b.first.x)
		  return a.first.y < b.first.y;
	  return a.first.x < b.first.x;
}

bool cmp1 (ppi a, ppi b) {
	if (quarter (a.first) == quarter (b.first))
		return cross (a.first, b.first) > 0;

	return quarter (a.first) < quarter (b.first);
}

int n;
mpi map;
vppi pts;

vppi ch_monotone (vppi pts) {
	int k = 0;
	vppi ans (pts.size () * 2);
	std::sort (pts.begin (), pts.end (), cmp);

	// lower hull
	for (int i = 0; i < pts.size (); i++) {

		// more than 2 points and while notConvex remove last point
		while (k >= 2 && checkTurn (ans [k - 2].first, ans [k - 1].first, pts [i].first) < 0)
			k--;
		ans [k++].first = pts [i].first;
		ans [k - 1].second = pts [i].second;
	}

	// upper hull
	for (int i = (int)pts.size () - 2, t = k + 1; i >= 0; i--) {
		// k >= t to not erase the lower hull ans while notConvex remove last point
		while (k >= t && checkTurn (ans [k - 2].first, ans [k - 1].first, pts [i].first) < 0)
			k--;
		ans [k++].first = pts [i].first;
		ans [k - 1].second = pts [i].second;
	}

	ans.resize (k);
	return ans;
}

void input () {
	scanf ("%d", &n);

	for (int i = 0; i < n; i++) {
		ll a, b; scanf ("%lld%lld", &a, &b);
		if (!map [{a, b}])
			pts.push_back ({{a, b}, i});
		map [{a, b}]++;
	}
	solve ();
}

void solve () {
	vppi ans = ch_monotone (pts);
	printf ("%d\n", (int)ans.size () - 1);
	//ans.pop_back ();

	std::sort (ans.begin (), ans.end (), cmp1);

	for (int i = 0; i < ans.size () - 1; i++)
		printf ("%d ", ans [i].second + 1);
	puts ("");

	ld per = 0, area = 0;
	for (int i = 0; i < ans.size () - 1; i++)
		per += dst (ans [i].first, ans [i + 1].first);
	printf ("%.20Lf\n", per);

	for (int i = 0; i < ans.size () - 1; i++) {
		area += (ld)ans [i].first.x * (ld)ans [i + 1].first.y;
		area -= (ld)ans [i].first.y * (ld)ans [i + 1].first.x;
	}
	printf ("%.20Lf\n", std::abs (area / 2.0));

}

int main () {
	input ();
	return 0;
}
