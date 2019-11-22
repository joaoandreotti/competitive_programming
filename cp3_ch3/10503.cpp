#include <bits/stdc++.h>

typedef std::pair <int, int> pi;

const int MAXN = 14;

int n, m;
pi arr [MAXN];
pi le, re;
int flag;

void func (int usd, int count, pi lp) {
  //printf ("used: %d, count: %d, lp: {%d, %d}\n", usd, count, lp.first, lp.second);

  if (count == n && lp.second == re.first) {
    flag = 1;
    return;
  }

  for (int i = 0; i < m; i++) {
    //printf ("used? %d\n", (usd >> i) & 1);
    if ((usd >> i) & 1) {
      usd &= INT_MAX - (1 << i); // set the domino as used
      if (arr [i].first == lp.second)
        func (usd, count + 1, arr [i]);

      if (arr [i].second == lp.second)
        func (usd, count + 1, {arr [i].second, arr [i].first});

      usd |= 1 << i; // next iter set this as not used
    }
  }

}

int main () {
  while (scanf ("%d", &n) && n != 0) {
    scanf ("%d", &m);
    scanf ("%d%d", &le.first, &le.second);
    scanf ("%d%d", &re.first, &re.second);

    for (int i = 0; i < m; i++)
      scanf ("%d%d", &arr [i].first, &arr [i].second);

    flag = 0;

    func (INT_MAX, 0, le);

    if (flag)
      puts ("YES");
    else
      puts ("NO");
  }
  return 0;
}
