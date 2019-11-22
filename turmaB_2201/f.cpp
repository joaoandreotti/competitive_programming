#include <bits/stdc++.h>

const int MAXN = 1e2, MAXT = 2e2 + 1;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, t, m1, m2;
int tms_fw [MAXT], tms_bw [MAXT], fs [MAXN], ls [MAXN];
int sumt_fw [MAXT], sumt_bw [MAXT];

long long func (int tm, int stn) {
  if (tm > t || stn < 0 || stn >= n)
    return INF;

  long long ans = INF;
  if (stn == (n - 1))
    ans = t - tm;


  printf ("tm: %d, stn: %d, ans: %lld\n", tm, stn, ans);
  for (int i = 0; i < m1; i++) {
    long long wst;
    if (stn)
      wst = (fs [i] + sumt_fw [stn - 1]) - tm;
    else
      wst = (fs [i]) - tm;
    if ((fs [i] + sumt_fw [stn]) >= tm) {
      //func (fs [i] + sumt_fw [stn] + tm, stn + 1);
      ans = std::min ((long long)wst + func (fs [i] + sumt_fw [stn], stn + 1), ans);
    }
  }

  for (int i = 0; i < m2; i++) {
    long long wst;
    if (stn == (n-1))
      wst = (ls [i]) - tm;
    else
      wst = (ls [i] + sumt_bw [stn + 1]) - tm;
    if ((ls [i] + sumt_bw [stn]) >= tm) {
      //func (ls [i] + sumt_bw [stn] + tm, stn - 1);
      ans = std::min ((long long)wst + func (ls [i] + sumt_bw [stn], stn - 1), ans);
    }
  }


  return ans;
}

int main () {
  while (scanf ("%d%d", &n, &t) && n != 0) {
    for (int i = 0; i < n - 1; i++) {
      scanf ("%d", tms_fw + i);
      tms_bw [i] = tms_fw [i];
      if (i)
        sumt_fw [i] += tms_fw [i] + sumt_fw [i - 1];
      else
        sumt_fw [i] = tms_fw [i];

    }

    for (int i = 0; i < n - 1; i++) {
      if (i)
        sumt_bw [(n - 2) - i] += tms_bw [(n - 2) - i] + sumt_bw [((n - 2) - i) + 1];
      else
        sumt_bw [(n - 2) - i] = tms_bw [(n - 2) - i];

      printf ("sumt_bw [%d]: %d\n", (n - 2) - i, sumt_bw [(n - 2) - i]);
    }

    scanf ("%d", &m1);
    for (int i = 0; i < m1; i++)
      scanf ("%d", fs + i);

    scanf ("%d", &m2);
    for (int i = 0; i < m2; i++)
      scanf ("%d", ls + i);

    printf ("%lld\n", func (0, 0));
  }
  return 0;
}
