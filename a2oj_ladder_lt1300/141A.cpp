#include <bits/stdc++.h>

std::map <char, int> names, scr;

int main () {
  std::string nm1, nm2, lt;
  std::cin >> nm1 >> nm2 >> lt;
  
  for (int i = 0; i < nm1.size (); i++)
    names[nm1[i]]++;
  for (int i = 0; i < nm2.size (); i++)
    names[nm2[i]]++;
  for (int i = 0; i < lt.size (); i++)
    scr[lt[i]]++;

  auto i = names.begin ();
  auto j = scr.begin ();

  /*
  puts ("Names: ");
  for (i = names.begin (); i != names.end (); i++)
    printf ("%c", i->first);

  puts ("\nScr: ");
  for (j = scr.begin (); j != scr.end (); j++)
    printf ("%c", j->first);
  puts ("");
  */

  if (names == scr)
    printf ("YES");
  else
    printf ("NO");



  return 0;
}
