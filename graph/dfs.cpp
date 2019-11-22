#include <bits/stdc++.h>

int _time = 0;
std::vector <std::vector <int> > adj;
std::vector <int> low;
std::vector <int> visited;
std::vector <int> disc;

void dfs (int u, int father) {
  int flag = 0;
  int num_child = 0;
  visited[u] = 1;
  disc[u] = low[u] = _time++;

  for (auto x : adj [u]) {
    if (!visited [x]) {
      dfs (x, u);
      num_child++; 
      if (low [x] >= disc [u]) 
        flag = 1; 
      low [u] = std::min (low [u], low [x]); 
      if (low [x] > disc [u])                           
        ;//printf ("(%d, %d) eh aresta de corte\n", u, x); 
    }
    else if (x != father) { 
      low [u] = std::min (low [u], disc [x]); 
    }
  }

  
  if (u == 0 && num_child >= 2) 
    ;//printf ("%d eh vertice de corte\n", u);
  else if (u != 0 && flag) 
    ;//printf ("%d eh vertice de corte\n", u);
}

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  adj.resize (n);
  low.resize (n);
  disc.resize (n);
  visited.resize (n);

  //fazer entrada

  dfs (0, 0);

  return 0;
}
