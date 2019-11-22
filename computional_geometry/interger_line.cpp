#include <bits/stdc++.h>

typedef long long ll;

struct point {ll x, y;};
struct line {
  ll a, b, c; //ax - by = c
  bool operator <(const line& rhs) const {
    return std::make_tuple(a, b, c) < std::make_tuple(rhs.a, rhs.b, rhs.c);
  }
};

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

  return {a, b, c};
}

bool areParallel(line l1, line l2) {
  return (l1.a == l2.a) && (l1.b == l2.b);
}

bool areSame(line l1, line l2) {
  return areParallel(l1, l2) && (l1.c == l2.c);
}
