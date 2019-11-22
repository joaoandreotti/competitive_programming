#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

int t, n, m;
int power, monster;
int mst [MAXN], best_p [MAXN];

void input () {
  scanf ("%d", &t);

  for (int cs = 0; cs < t; cs++) {
    scanf ("%d", &n);
    
    monster = 0;
    for (int i = 0; i < n; i++) {
      scanf ("%d", mst + i);

      monster = std::max (monster, mst [i]);
    }


    scanf ("%d", &m);
    memset (best_p, 0, (4 * n) + 4);
    power = 0;
    for (int i = 0, p, s; i < m; i++) {
      scanf ("%d%d", &p, &s);
      // in every endurance S we have the best power P
      best_p [s] = std::max (best_p [s], p);

      power = std::max (p, power);
    }

    // now we need to update the best Power with endurance I
    // to do so, the Ith endurance get the (I + 1)th best Power
    // this works because with the endurance 5 have power 3
    // and the endurance 6 have power 4, we update a smaller endurance
    for (int i = n - 1; i >= 1; i--)
      best_p [i] = std::max (best_p [i], best_p [i + 1]);

    solve ();
  }
}

void solve () {
  for (int i = 1; i <= n; i++) // n == MAX_S
    printf ("for %d, best_power: %d\n", i, best_p [i]);

  //puts ("AA");
  if (monster > power) {
    puts ("-1");
    return;
  }

  int day = 1, pos = 1, max = mst [0];
  for (int i = 0; i < n; i++) {
    max = std::max (max, mst [i]);
    //printf ("{%d, %d} -- {%d, %d}\n", max, mst [i], pos, best_p [pos]);
    if (max <= best_p [pos])
      pos++;
    else {
      //puts ("----");
      day++;
      max = mst [i];
      i--;
      pos = 1;
    }
  }

  printf ("%d\n", day);

}

int main () {
  input ();
  return 0;
}
