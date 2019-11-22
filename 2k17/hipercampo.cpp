#include <bits/stdc++.h>

std::vector <std::pair <int, int> > points;
std::set <std::pair <int, int> > set[110];
std::set <std::pair <int, int> > s_aux;
std::map <std::pair <int, int>, int > map;
int arr[110];

std::pair <int, int> operator- (std::pair <int, int> a, std::pair <int, int> b) {
  return std::make_pair ((a.first - b.first), (a.second - b.second));
}

int operator* (std::pair <int, int> a, std::pair <int, int> b) {
  return ((a.first * b.second) - (a.second * b.first));
}

int main () {
  int n, A, B;
  scanf ("%d%d%d", &n, &A, &B);

  for (int i = 0; i < n; i++) {
    int a, b;
    scanf ("%d%d", &a, &b);
    points.push_back ({a, b});
    map [{a, b}] = i;
  }

  for (int i = 0; i < points.size (); i++) {
    //printf ("testing %d: (%d, %d)\n", i, points[i].first, points[i].second);
    for (int j = 0; j < points.size (); j++) {
      //printf ("\tchecking %d: (%d, %d)\n", j, points [j].first, points[j].second);
      //printf ("\t\t(%d, %d) to (%d, %d): %d\n", points[i].first, points[i].second, A, 0, (points[j] - points[i]) * (points[j] - std::make_pair (A, 0)));
      //printf ("\t\t(%d, %d) to (%d, %d): %d\n", points[i].first, points[i].second, B, 0, (points[j] - points[i]) * (points[j] - std::make_pair (B, 0)));
      if (i != j) {
        if ((points[j] - points[i]) * (points[j] - std::make_pair (A, 0)) > 0) {
          if ((points[j] - points[i]) * (points[j] - std::make_pair (B, 0)) < 0)
            set [i].insert (points[j]);
        }
//        if ((points[j] - points[i]) * (points[j] - std::make_pair (A, 0)) < 0) {
//          if ((points[j] - points[i]) * (points[j] - std::make_pair (B, 0)) > 0)
//            set [i].insert (points[j]);
//        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    //printf ("i: %d (%d, %d)\n", i, points[i].first, points[i].second);
    s_aux.insert ({set[i].size (), i});
    for (auto j = set[i].begin (); j != set[i].end (); j++) {
      //printf ("\tst: %d, nd: %d\n", j->first, j->second);
    }
  }

  long long ans = 0;
  auto it = s_aux.rbegin ();
  while (it != s_aux.rend ()) {
    int best = 0;
    for (auto j = set[i->second].begin (); j != set[i->second].end (); j++) {
      //printf ("best: %d, j: (%d, %d),set[map[*j]].size (): %d\n", best, j->first, j->second, set[map[*j]].size ());
      best = std::max (best, (int)set[map[*j]].size () + 1);
    }
    it++;
  }

  printf ("%lld\n", ans);
  return 0;
}
