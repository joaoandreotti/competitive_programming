#include <bits/stdc++.h>

// ESTE ALGORITMO NAO FOI TESTADO E NAO FACO A MENOR IDEIA SE FUNCIONA OU NAO -- FAVOR REFAZER URGENTEMENTE
//
const int MAXN = 1e3;

int n, m; // num vertices L and R
int dist [MAXN]; // only to L neightbors
int matchL [MAXN], matchR [MAXN]; // pais from the match
std::queue <int> Q; // vertice 0 virtual

int BFS ();
int DFS (int);

int hopcraftkarp () {
  for (int i = 1; i <= n; i++) matchL [i] = 0;
  for (int i = 1; i <= m; i++) matchR [i] = 0;

  while (BFS ()) { // BFS returns true if reach the sink (found a A.P.)
    for (int i = 1; i <= n; i++) {
      if (matchL [i] == 0 && DFS (i)) // if L if free and found a A.P.
        matching++;
    }
  }

  return matching;
}

int BFS () {
  for (int i = 1; i <= n; i++) {
    if (matchL [i] == 0) {
      dist [i] = 0;
      Q.push (i);
    }
    else {
      dist [i] = INT_MAX;
    }

    dist [0] = INT_MAX;
  }

  while (!Q.empty ()) { // queue has only the sink of left vertices
    int l = Q.front (); Q.pop ();
    if (dist [l] < dist [0]) {
      for (int r : adj [l]) {
        if (dist [matchR [r]] == INT_MAX) { // if matching right pair == not explored
          dist [matchR [r]] = dist [l] + 1;
          Q.push (matchR [r]);
        }
      }
    }
  }

  return dist [0] < INT_MAX;
}

int DFS (int x) {
  if (x == 0)
    return true;

  for (int r : adj [l]) {
    if (dist [matchR [r]] == (dist [l] + 1)) {
      if (dfs (matchR [r])) {
        std::swap (matchL [l], matchR [r]);
        return true;
      }
    }
  }

  return false;
}


int main () {
  return 0;
}
