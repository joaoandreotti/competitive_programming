#include <bits/stdc++.h>

struct point {
  int x = 0, y = 0;
};
point arr [3];

int dot (point p1, point p2, point p3) {
  point v1, v2;
  v1.x = (p1.x - p2.x);
  v1.y = (p1.y - p2.y);
  v2.x = (p1.x - p3.x);
  v2.y = (p1.y - p3.y);

  if ((v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;

  v1.x = (p2.x - p1.x);
  v1.y = (p2.y - p1.y);
  v2.x = (p2.x - p3.x);
  v2.y = (p2.y - p3.y);

  if ((v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;

  v1.x = (p3.x - p1.x);
  v1.y = (p3.y - p1.y);
  v2.x = (p3.x - p2.x);
  v2.y = (p3.y - p2.y);

  if ((v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;

  return 0;
}

int almost (point p1, point p2, point p3) {
  point v1, v2;
  v1.x = (p1.x - p2.x);
  v1.y = (p1.y - p2.y);
  v2.x = (p1.x - p3.x);
  v2.y = (p1.y - p3.y);

  v1.x--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.x += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.x--;
  v1.y--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.y += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.y--;
  v2.x--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.x += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.x--;
  v2.y--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.y += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;

  v1.x = (p2.x - p1.x);
  v1.y = (p2.y - p1.y);
  v2.x = (p2.x - p3.x);
  v2.y = (p2.y - p3.y);

  v1.x--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.x += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.x--;
  v1.y--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.y += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.y--;
  v2.x--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.x += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.x--;
  v2.y--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.y += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;

  v1.x = (p3.x - p1.x);
  v1.y = (p3.y - p1.y);
  v2.x = (p3.x - p2.x);
  v2.y = (p3.y - p2.y);

  v1.x--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.x += 2;
  if (((v1.x != 0 && v1.y != 0) &&v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.x--;
  v1.y--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.y += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v1.y--;
  v2.x--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.x += 2;
  if (((v1.x != 0 && v1.y != 0) &&v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.x--;
  v2.y--;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;
  v2.y += 2;
  if ((v1.x != 0 && v1.y != 0) &&(v1.x*v2.x + v1.y * v2.y) == 0)
    return 1;

  return 0;
}

int main () {
  int a, b;
  for (int i = 0; i < 3; i++) {
    scanf ("%d%d", &a, &b);
    arr [i].x = a; arr [i].y = b;
  }

  if (dot (arr [0], arr [1], arr [2])) {
    puts ("RIGHT");
    return 0;
  }
  else {
    if (almost (arr [0], arr [1], arr [2])) {
      puts ("ALMOST");
      return 0;
    }
  }
  puts ("NEITHER");
    

  return 0;
}
