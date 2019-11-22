#include<bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;

int main () {
  int t;
  long double x1, y1, r1;
  long double x2, y2, r2;
  long double s1, s2, s3, s4;
  long double t1, t2, t3, t4;
  long double d, men, mai;
  long double pro, c, a;

  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    scanf("%Lf%Lf%Lf", &x1, &y1, &r1);
    scanf("%Lf%Lf%Lf", &x2, &y2, &r2);

    d = hypotl(x1 - x2, y1 - y2);
    pro = r1 / d;
    men = min(r1, r2);
    mai = max(r1, r2);

    if (abs(x1 - x2) < EPS && abs(y1 - y2) < EPS && abs(r1 - r2) < EPS) {
      printf("Oops, too many points\n");
    } else if (d > r1 + r2 || d + men < mai) {
      printf("There are no points\n");
    } else if (abs(d - r1 - r2) < EPS || abs(d + men - mai) < EPS) {
      t1 = (x2 - x1) * pro;
      t2 = (y2 - y1) * pro;
      c = (r1 * r1 + d * d - r2 * r2) / (2 * r1 * d);
      a = acos(c);

      s1 = t1 * cos(a) - t2 * sin(a);
      s2 = t2 * sin(a) + t2 * cos(a);

      printf("There are only 1 of them\n");
      printf("%Lf %Lf\n", s1 + x1, s2 + y1);

    } else {
      t1 = (x2 - x1) * pro;
      t2 = (y2 - y1) * pro;
      c = (r1 * r1 + d * d - r2 * r2) / (2 * r1 * d);
      a = acos(c);

      s1 = t1 * cos(a) - t2 * sin(a);
      s2 = t1 * sin(a) + t2 * cos(a);
      s3 = t1 * cos(-a) - t2 * sin(-a);
      s4 = t1 * sin(-a) + t2 * cos(-a);

      if (s1 > s3 || abs(s1 - s3) < EPS && s2 > s4) {
        swap(s1,s3);
        swap(s2,s4);
      }

      printf("There are only 2 of them\n");
      printf("%Lf %Lf\n", s1 + x1, s2 + y1);
      printf("%Lf %Lf\n", s3 + x1, s4 + y1);
    }
    puts("");
  }

  return 0;
}
