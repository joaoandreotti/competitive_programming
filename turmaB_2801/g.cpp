#include <bits/stdc++.h>

typedef std::vector <int> vi;

vi factors (int n) {
  vi ans;
  for (int i = 2; i*i <= n; i++) {
    while (n % i == 0) {
      ans.push_back (i);
      n /= i;
    }
  }
  if (n > 1)
    ans.push_back (n);

  return ans;
}

int main () {
  int n, k; scanf ("%d%d", &n, &k);
  int a;
  vi aux = factors (k);
  std::map <int, int> kf;
  std::map <int, int> fac;
  std::set <int> set;
  for (int i = 0; i < aux.size (); i++) {
    kf [aux [i]]++;
  }

  for (int i = 0; i < n; i++) {
    scanf ("%d", &a);
    set.insert (a);
    //printf ("factors: %d\n", a);
    //printf ("%d ", aux [j]);
    //puts ("");
  }
  for (auto i = set.begin (); i != set.end (); i++) {
    aux = factors (*i);
    for (int j = 0; j < aux.size (); j++)
      fac [aux [j]]++;
  }

  for (auto i = fac.begin (); i != fac.end (); i++)
    printf ("{%d, %d} ", i->first, i->second);
  puts ("");

  int flag = 1;
  for (auto i = kf.begin (); i != kf.end (); i++) {
    printf ("{%d, %d} ", i->first, i->second);
    if (i->second > fac [i->first])
      flag = 0;
  }
  puts ("");

  if (flag)
    puts ("Yes");
  else
    puts ("No");
  return 0;
}
