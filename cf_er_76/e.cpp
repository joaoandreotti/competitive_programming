#include <bits/stdc++.h>

void input ();
void solve ();

const int MAXN = 2e5 + 1;

int a, b, c;
int arr [MAXN];
int d [MAXN];
int end [MAXN];

void input () {
  scanf ("%d%d%d", &a, &b, &c);

  for (int i = 0; i < a; i++)
    scanf ("%d", arr + i);
  std::sort (arr, arr + a);

  for (int i = a; i < (b + a); i++)
    scanf ("%d", arr + i);
  std::sort (arr + a, arr + (b + a));

  for (int i = (b + a); i < (c + b + a); i++)
    scanf ("%d", arr + i);
  std::sort (arr + (b + a), arr + (c + b + a));

  solve ();
}

void solve () {
  int n = a + b + c;

  /*
  for (int i = 0; i < n; i++)
    d [i] = 1;

  // n ** 2
  // d [i] is the LIS size for the element arr [i]
  // the ideia is that the d [j] for every j < i
  // is already calculated, so if we check for every
  // single element arr [j] that is less then arr [i]
  // the LIS will be d [j] + 1
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (arr [j] < arr [i])
        d [i] = std::max (d [i], d [j] + 1);
        */


  /*
  end [0] = -INT_MAX;
  for (int i = 1; i <= n; i++)
    end [i] = INT_MAX;
  // n ** 2
  // end [i] is the element at which the subsequence
  // of length i termites e.g. end [3] will contain the
  // element that the subsequence of size 3 terminates
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= n; j++)
      // if the element of the subsequence of size (j - 1) is
      // less then the element arr [i] AND
      // the element arr [i] is less then the element in the
      // subsequence of size j
      if (end [j - 1] < arr [i] && arr [i] < end [j])
        end [j] = arr [i];
  for (int i = 0; i <= n; i++)
    printf ("%d ", end [i]);
  puts ("");
        */

  end [0] = -INT_MAX;
  for (int i = 1; i <= n; i++)
    end [i] = INT_MAX;
  // n log n
  // the same solution as before, but insted of
  // bruting the element in end [j] that is strictly greater
  // the arr [i], we just need a binary search (upper bound)
  for (int i = 0; i < n; i++) {
    auto x = std::lower_bound (end, end + n, arr [i]) - end; // get the element position
    //printf ("arr [%d]: %d, x: %d\n", i, arr [i], x);
    if (end [x - 1] < arr [i] && arr [i] < end [x])
      end [x] = arr [i];
  }

  puts ("END:");
  for (int i = 0; i <= n; i++)
    printf ("%d ", end [i]);
  puts ("");

  int lis = 0;
  for (int i = 0; i <= n; i++) {
    if (end [i] < INT_MAX) {
      lis = i;
      printf ("lis: %d\n", lis);
    }
  }

  printf ("%d\n", n - lis);

}

int main () {
  input ();
  return 0;
}
