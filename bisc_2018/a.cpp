#include <bits/stdc++.h>

void input ();
void solve ();

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

typedef std::pair <float, float> pi;
typedef std::vector <Point> vpi;

int n;
vpi arr;

Point center;

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

// compare function by polar angle
bool cmp (Point a, Point b) {
  a = a - center; b = b - center; // relative points from a pivot
  if (quarter (a) == quarter (b))
    return cross (a, b) > 0;

  return quarter (a) < quarter (b);
}

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf ("%d%d", &a, &b);
		arr.push_back ({a, b});
	}
	solve ();
}

void solve () {
	//std::random_shuffle (arr.begin (), arr.end ());
	std::sort (arr.begin (), arr.end (), cmp);
	arr.push_back ({arr [0].x, arr [0].y});
	float ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (float)arr [i].x * (float)arr [i + 1].y;
		ans -= (float)arr [i].y * (float)arr [i + 1].x;
	}
	printf ("%f\n", ans / 2.0);
}

int main () {
	input ();
	return 0;
}
