#include <bits/stdc++.h>

int main () {
  std::string tiles, sofa;
  std::cin >> tiles >> sofa;

  if (sofa.size () == 1) {
    printf ("%d\n", tiles.size ());
    return 0;
  }
  else if (tiles.size () == 1) {
    puts ("1");
    return 0;
  }

  long long ans = 0;
  for (int i = 0; i < (tiles.size () - sofa.size ()); i++) {
    int match = 1;
    int flag1 = 0, flag0 = 0;
    char one, zero;
    for (int j = 0; j < sofa.size (); j++) {
      if (sofa[j] == '1' && !flag1) {
        one = tiles [j + i];
        flag1 = 1;
      }
      else if (sofa[j] == '0' && !flag0) {
        zero = tiles [j + i];
        flag0 = 1;
      }

      if (sofa [j] == '1' && one != tiles [j + i]) {
        match = 0;
        break;
      }
      else if (sofa [j] == '0' && zero != tiles [j + i]) {
        match = 0;
        break;
      }
    }

    if (match)
      ans++;

    flag1 = 0;
    flag0 = 0;

    if (!match) {
      int count = i;
      for (int j = sofa.size () - 1; j >= 0; j--) {
        if (sofa[j] == '1' && !flag1) {
          one = tiles [count];
          flag1 = 1;
        }
        else if (sofa[j] == '0' && !flag0) {
          zero = tiles [count];
          flag0 = 1;
        }

        if (sofa [j] == '1' && one != tiles [count]) {
          match = -1;
          break;
        }
        else if (sofa [j] == '0' && zero != tiles [count]) {
          match = -1;
          break;
        }
        count++;
      }

      if (match != -1)
        ans++;
    }

  }

  int match = 1;
  int flag1 = 0, flag0 = 0;
  char one, zero;
  int i = (tiles.size () - sofa.size ());
  for (int j = 0; j < sofa.size (); j++) {
    if (sofa[j] == '1' && !flag1) {
      one = tiles [j + i];
      //printf ("one: %c\n", one);
      flag1 = 1;
    }
    else if (sofa[j] == '0' && !flag0) {
      zero = tiles [j + i];
      //printf ("zero: %c\n", zero);
      flag0 = 1;
    }

    if (sofa [j] == '1' && one != tiles [j + i]) {
      match = 0;
      break;
    }
    else if (sofa [j] == '0' && zero != tiles [j + i]) {
      match = 0;
      break;
    }
  }

  if (match)
    ans++;

  flag1 = 0;
  flag0 = 0;

  if (!match) {
    int count = i;
    for (int j = sofa.size () - 1; j >= 0; j--) {
      if (sofa[j] == '1' && !flag1) {
        one = tiles [count];
        //printf ("one: %c\n", one);
        flag1 = 1;
      }
      else if (sofa[j] == '0' && !flag0) {
        zero = tiles [count];
        //printf ("zero: %c\n", zero);
        flag0 = 1;
      }

      if (sofa [j] == '1' && one != tiles [count]) {
        match = -1;
        break;
      }
      else if (sofa [j] == '0' && zero != tiles [count]) {
        match = -1;
        break;
      }
      count++;
    }
    if (match != -1)
      ans++;
  }

  printf ("%lld\n", ans);
  return 0;
}
