#include <bits/stdc++.h>

int arr [(int)1e3];

int main () {
  int n; scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d", arr + i);


  if (n == 1) {
    puts ("0");
    return 0;
  }
  else if (n == 2) {
    if (arr [0] == 1 && arr [1] == 2)
      puts ("1");
    else if (arr [0] == 999 && arr [1] == 1000)
      puts ("1");
    else
      puts ("0");
    return 0;
  }

  std::set <int> v, f;

  for (int i = 0; (i + 1) < n; i++) {
    if (arr [i + 1] - arr [i] == 1) {
      v.insert (arr [i]);
      v.insert (arr [i + 1]);
    }
    else
      v.clear ();

    if (v.size () > f.size ())
      f = v;
    
  }

  if (f.size () == 0) {
    puts ("0");
    return 0;
  }

  int x = 0;
  if (*f.begin () != 1)
    x++;
  if (*f.rbegin () != 1000)
    x++;

  if (arr [n - 1] - *f.rbegin () == 1)
    f.insert (arr [n - 1]);

  for (auto i = f.begin (); i != f.end (); i++)
    printf ("%d ", *i);
  puts ("");

  if (f.size () - x < 0)
    puts ("0");

  printf ("%d\n", f.size () - x);

  return 0;
}
