#include <bits/stdc++.h>

#define y1 asoijfaosidjfaosidjfasiodjfoisadjfiaosjdfioasdjfoiasdjfoiadsjfoiasdjfiaosdjfoaisdjfiaosdjfioasdjfiodjsoiafsdj

void input ();
void solve ();

//typedef long double lf;

const long double EPS = 1e-9;

typedef struct lf {
	long double v;

	bool operator == (const lf& a) {
		if (std::abs (v - a.v) < EPS)
			return true;
		return false;
	}
	lf operator + (const lf& a) {
		return {v + a.v};
	}
	bool operator < (const lf& a) {
		if (std::abs (v - a.v) > EPS)
			return true;
		return false;
	}
} lf;

int n;
long double x1, y1;
long double x2, y2;
lf r1, r2;


long double dist () {
	return hypotl (x1 - x2, y1 - y2);
}

void input () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%Lf%Lf%Lf", &x1, &y1, &r1.v);
		scanf ("%Lf%Lf%Lf", &x2, &y2, &r2.v);
		if (r1 < r2) { // r1 always the biggest
			std::swap (x1, x2);
			std::swap (y1, y2);
			std::swap (r1, r2);
		}
		solve ();
		puts ("");
	}
}

void solve () {
	std::vector <std::pair <long double, long double> > ans;
	if (dist () > (r1 + r2).v) // no intersection
		puts ("There are no points");
	else if (dist () <= std::min (r1.v, r2.v)) { // inside
		if (x1 == x2 && y1 == y2 && r1.v == r2.v) // same
			puts ("Oops, too many points");
		else if (((dist () + r2.v) - r1.v) < EPS) { // 1 point
			puts ("There are only 1 of them");
			long double p = dist () / r1.v;
			x2 /= p; y2 /= p;
			printf ("%Lf %Lf\n", x2, y2);
		}
		else if (((dist () + r2.v) - r1.v) > EPS) { // 2 point
			puts ("There are only 2 of them");
			long double a = r1.v, b = r2.v, c = dist ();
			long double cos_theta = ((b * b) - (a * a) - (c * c)) / -((long double)2 * a * c);
			long double theta = acosl (cos_theta);
			long double sin_theta = sinl (theta);
			//printf ("theta %Lf, cos: %Lf, sin: %Lf\n", theta, cos_theta, sin_theta);
			long double p = dist () / r1.v;
			long double tx = x2 - x1, ty = y2 - y1;
			tx /= p; ty /= p;
			//printf ("{%.10Lf, %.10Lf}\n", tx, ty);
			long double x = (tx * cos_theta) - (ty * sin_theta);
			long double y = (tx * sin_theta) + (ty * cos_theta);
			ans.push_back ({x + x1, y + y1});
			//printf ("%Lf %Lf\n", x + x1, y + y1);
			x = (tx * cosl (-theta)) - (ty * sinl (-theta));
			y = (tx * sinl (-theta)) + (ty * cosl (-theta));
			ans.push_back ({x + x1, y + y1});

			std::sort (ans.begin (), ans.end ());
			for (int i = 0; i < ans.size (); i++)
				printf ("%.10Lf %.10Lf\n", ans [i].first, ans [i].second);
			//printf ("%.10Lf %.10Lf\n", x + x1, y + y1);
		}
		else // no points
			puts ("There are no points");
	}
	else { // [1,2] points
		long double a = r1.v, b = r2.v, c = dist ();
		long double cos_theta = ((b * b) - (a * a) - (c * c)) / -((long double)2 * a * c);
		long double theta = acosl (cos_theta);
		long double sin_theta = sinl (theta);
		//printf ("theta %Lf, cos: %Lf, sin: %Lf\n", theta, cos_theta, sin_theta);
		long double p = dist () / r1.v;
		if (std::abs (dist () - (r1 + r2).v) < EPS) { // 1 point
			puts ("There are only 1 of them");
			x2 /= p; y2 /= p;
			printf ("%Lf %Lf\n", x2, y2);
		}
		else { // 2 points
			puts ("There are only 2 of them");
			long double tx = x2 - x1, ty = y2 - y1;
			tx /= p; ty /= p;
			//printf ("{%.10Lf, %.10Lf}\n", tx, ty);
			long double x = (tx * cos_theta) - (ty * sin_theta);
			long double y = (tx * sin_theta) + (ty * cos_theta);
			ans.push_back ({x + x1, y + y1});
			x = (tx * cosl (-theta)) - (ty * sinl (-theta));
			y = (tx * sinl (-theta)) + (ty * cosl (-theta));
			ans.push_back ({x + x1, y + y1});

			std::sort (ans.begin (), ans.end ());
			for (int i = 0; i < ans.size (); i++)
				printf ("%.10Lf %.10Lf\n", ans [i].first, ans [i].second);
		}
	}
}

int main () {
	input ();
	return 0;
}
