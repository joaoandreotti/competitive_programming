#include <bits/stdc++.h>

std::vector <int> arr;
int n, cd, ans, bm_ans;

void func (int pos, int bm, int sum) {
  //printf ("pos: %d, bm: %d, sum: %d\n", pos, bm, sum);
  if (sum > n)
    return;

  if (pos >= cd) {
    if (ans < sum) {
      ans = sum;
      bm_ans = bm;
      //printf ("new => ans: %d, bm: %d\n", ans, bm_ans);
    }

    return;
  }
  func (pos + 1, bm, sum);
  func (pos + 1, bm | (1 << pos), sum + arr [pos]);
}

int main () {

  while (scanf ("%d", &n) != EOF) {
    scanf ("%d", &cd);
    arr.clear ();
    arr.resize (cd);
    //printf ("cd: %d\n", cd);

    bm_ans = ans = 0;

    for (int i = 0; i < cd; i++)
      scanf ("%d", &arr [i]);

    func (0, 0, 0);
    

    /*
    printf ("bm: %d => ", bm_ans);
    for (int i = 31; i >= 0; i--) {
      printf ("%d", (bm_ans >> i) & 1);
    }
    puts ("");
    printf ("ans: %d\n", ans);
    */

    for (int i = 0; i < cd; i++) {
      if ((bm_ans >> i) & 1)
        printf ("%d ", arr [i]);
    }
    printf ("sum:%d\n", ans);


  }
  return 0;
}
