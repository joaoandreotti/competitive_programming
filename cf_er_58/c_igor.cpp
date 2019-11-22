#include <bits/stdc++.h>

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef long long unsigned llu;
typedef long double ld;
typedef std::pair<int, int> pii;
//typedef std::pair<int, pii> iii;
typedef std::pair<pii, int> iii;

const int N = 1e5+10;
int t, n, ans[N];
iii seg[N];

bool possible () {
  int limit = seg[0].st.nd;
  ans[seg[0].nd] = 1;
  for (int i = 1; i < n; i++) {
    if (seg[i].st.st <= limit) {
      limit = std::max(limit, seg[i].st.nd);
      ans[seg[i].nd] = 1;
    } else {
      return true;
    }
  }

  return false;
}

int main() {
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
      scanf("%d%d", &seg[i].st.st, &seg[i].st.nd);
      seg[i].nd = i;
    }

    std::sort(seg, seg+n);
    for (int i = 0; i < n; i++)
      ans[i] = 2;
    if (possible()) {
      for (int i = 0; i < n; i++)
        printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
    } else {
      printf("-1\n");
    }
  }

  return 0;
}
