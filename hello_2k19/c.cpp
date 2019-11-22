#include <bits/stdc++.h>

const int MAXN = 2e5;

std::string bkt [MAXN];
std::map <std::pair <int, int>, int> vp;

bool cmp (std::pair <std::pair <int, int>, int> a, std::pair <int, int> b) {
  if (b.first != a.first.first)
    return b.first > a.first.first;
  return b.second > a.first.second;
}

int main () {
  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    std::cin >> bkt [i];


  int l = 0, r = 0;
  int ul = 0, ur = 0;
  // O(5e5)
  for (int i = 0; i < n; i++) {
    ul = ur = 0;
    l = r = 0;
    for (int j = 0; j < bkt[i].size (); j++) {
      if (bkt [i][j] == ')') {
        l++;
        if (l > r) {
          ul++;
          l--;
        }
      }
      else
        r++;
    }
    l = r = 0;
    for (int j = bkt[i].size () - 1; j >= 0; j--) {
      if (bkt [i][j] == '(') {
        r++;
        if (r > l) {
          ur++;
          r--;
        }
      }
      else
        l++;
    }

    vp[{ul, ur}]++;
  }

  /*
  for (auto i = vp.begin (); i != vp.end (); i++) {
    printf ("{{%d, %d}, %d} ", (*i).first.first, (*i).first.second, i->second);
  }
  puts ("");
  */

  long long ans = 0;
  for (auto i = vp.begin (); i != vp.end (); i++) {
    //printf ("%d | %d\n", vp [{i->first.second, i->first.first}], i->second);
    if (((*i).first.first == 0 || (*i).first.second == 0)) {
      if (i->first.second == i->first.first) {
        ans += i->second / 2;
        i->second = 0;
        continue;
      }
      ans += std::min (vp [{i->first.second, i->first.first}], i->second);
      i->second = 0;
      vp [{i->first.second, i->first.first}] = 0;
    }
  }
  printf ("%lld\n", ans);

  /*
  std::set <std::pair <std::pair <int, int>, int> > set;
  for (auto i = vp.begin (); i != vp.end (); i++) {

    auto s = std::lower_bound (vp.begin (), vp.end (), std::make_pair (i->first.second, i->first.first), cmp);



    printf ("{{%d, %d}, %d} && {{%d, %d}, %d}\n", (*s).first.first, (*s).first.second, (*s).second, (*i).first.first, (*i).first.second, (*i).second);

    if (set.find ((*i)) != set.end () || set.find ((*s)) != set.end ()) {
      continue;
    }
    if (s != vp.end ()) {
      if (((*i).first.second == 0 || (*s).first.second == 0)) {

        if (((*s).first.first == (*i).first.second && (*s).first.second == (*i).first.first) && s != i) {
          set.insert ((*i));
          set.insert ((*s));
        }
      }
    }

    for (auto j = set.begin (); j != set.end (); j++) {
      printf ("{{%d, %d}, %d} ", (*j).first.first, (*j).first.second, (*j).second);
    }
    puts ("---");
  }
  */


  //printf ("%d\n", set.size () / 2);

  return 0;
  
}
