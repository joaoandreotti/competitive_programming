#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXL = 26;

int t, n;
int arr [MAXL], brr [MAXL];
std::string a, b;
std::vector <std::pair <int, int> > changes;

void input () {
  scanf ("%d", &t);
  for (int cs = 0; cs < t; cs++) {
    changes.clear ();
    memset (arr, 0, sizeof arr);
    memset (brr, 0, sizeof brr);

    scanf ("%d", &n);
    std::cin >> a >> b;

    solve ();
  }
}

void solve () {
  for (int i = 0; i < n; i++) {
    arr [a [i] - 'a']++;
    brr [b [i] - 'a']++;
  }

  for (int i = 0; i < 26; i++)
    if ((arr [i] + brr [i]) % 2) {
      puts ("No");
      return;
    }

  for (int i = 0; i < n; i++) {
    if (a [i] != b [i]) {
      for (int j = i + 1; j < n; j++) {
        //printf ("{%c, %c}\n", a [i], b [j]);
        if (a [i] == a[j]) {
          std::swap (a [j], b [i]);
          changes.push_back ({j, i});
          break;
        }
        if (a [i] == b [j]) {
          std::swap (a [j], b [j]);
          std::swap (a [j], b [i]);
          changes.push_back ({j, j});
          changes.push_back ({j, i});
          break;
        }
      }
    }
    //printf ("a: %s, b: %s\n", a.c_str (), b.c_str ());
  }

  puts ("Yes");
  printf ("%d\n", changes.size ());
  for (int i = 0; i < changes.size (); i++)
    printf ("%d %d\n", changes [i].first + 1, changes [i].second + 1);

}

int main () {
  input ();
  return 0;
}

