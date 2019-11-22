#include <bits/stdc++.h>

const int MAXN = 6;

typedef std::pair <std::string, std::string> ps;

int n, t;
std::string aw [MAXN];
std::set <ps> match [MAXN];
std::set <std::string> sm;

bool cmp (ps a, std::string b) {
  return a.second < b;
}

int check (int p, std::string str) {
  //printf ("using substr: %s\n", str.c_str ());
  for (int i = 0; i < n; i++)
    if (i != p && str.size () <= aw [i].size ()  && (aw [i].substr (aw [i].size () - str.size (), str.size ()).find (str) != std::string::npos)) {
      //printf ("found: %s in %s\n", str.c_str (), aw [i].c_str ());
      auto lb = std::lower_bound (match [p].begin (), match [p].end (), aw [i], cmp);
      //printf ("lb: {%s, %s}\n", (*lb).first.c_str (), (*lb).second.c_str ());
      if ((*lb).second != aw [i]) {
        match [p].insert ({str, aw [i]});
        sm.insert (str);
      }
    }
  return 0;
}

void input ();
void sol (int);

void input () {
  scanf ("%d", &t);
  for (int cs = 1; cs <= t; cs++) {
    // input
    sm.clear ();
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
      match [i].clear ();
      aw [i] = "";
      std::cin >> aw [i];
    }
    sol (cs);
  }
}

void sol (int cs) {
  printf ("Case #%d: ", cs);
  std::sort (aw, aw + n);
//  for (int i = 0; i < n; i++)
//    std::cout << "str: " << aw [i] << std::endl;

  puts ("");
  for (int i = 0; i < n; i++) {
    printf ("str: %s\n", aw [i].c_str ());
    for (int j = 0; j < aw [i].size (); j++) {
      check (i, aw [i].substr (j, aw [i].size () - j));
    }
  }

  for (int i = 0; i < n; i++) {
    printf ("matches with str %s:\n", aw [i].c_str ());
    for (auto j = match [i].begin (); j != match [i].end (); j++)
      printf ("{%s, %s}\n", (*j).first.c_str (), (*j).second.c_str ());
  }
  /*
  puts ("suffix matches:");
  for (auto j = sm.begin (); j != sm.end (); j++)
    printf ("{%s}\n", (*j).c_str ());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    printf ("matches with str %s:\n", aw [i].c_str ());
    for (auto j = match [i].begin (); j != match [i].end (); j++)
      printf ("{%s, %s}\n", (*j).first.c_str (), (*j).second.c_str ());
  }
    */
  printf ("%d\n", int (sm.size ()) * 2);

}

int main () {
  input ();
  return 0;
}
