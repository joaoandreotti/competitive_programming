#include <bits/stdc++.h>

struct flow_edge {
  int v, u; // flow from 'v' to 'u'
  long long cap, flow = 0; // cap is the max flow in this edge
  flow_edge (int v, int u, long long cap) : v (v), u (u), cap (cap) {}
};

void input ();
void solve ();

typedef long long ll;
typedef std::pair <int, int> pi;
typedef std::vector <int> vi;
typedef std::vector <vi> vvi;
typedef std::vector <pi> vpi;
typedef std::vector <vpi> vvpi;
typedef std::vector <flow_edge> vf;
typedef std::queue <int> qi;
typedef std::vector <std::string> vs;


const long long flow_inf = 0x3f3f3f3f3f3f3f3f, MAXN = 1e2 + 10;
int n, m, p;
int s, t;
int pos;
int ins [MAXN][MAXN];

vs arr;
vf edges;
vvi adj;
vi level, ptr;
qi q;

void dinic (int n1, int s1, int t1) {
  n = n1; s = s1; t = t1;
  adj.clear ();
  level.clear ();
  ptr.clear ();

  adj.resize (n);
  level.resize (n);
  ptr.resize (n);
}

void add_edge (int v, int u, long long cap) {
  edges.push_back (flow_edge (v, u, cap));
  //edges.push_back (flow_edge (u, v, 0));
  adj [v].push_back (pos);
  //adj [u].push_back (pos + 1);
  pos += 1;
}

bool bfs () {
  while (!q.empty ()) {
    int v = q.front ();
    q.pop ();
    for (int id : adj [v]) {
      if (edges [id].cap - edges [id].flow < 1)
        continue;
      if (level [edges [id].u] != -1)
        continue;
      level [edges [id].u] = level [v] + 1;
      q.push (edges [id].u);
    }
  }
  return level [t] != -1;
}

long long dfs (int v, long long pushed) {
  if (pushed == 0)
    return 0;
  if (v == t)
    return pushed;

  for (int &cid = ptr [v]; cid < (int)adj [v].size (); cid++) {
    int id = adj [v][cid];
    int u = edges [id].u;

    if (level [v] + 1 != level [u] || edges [id].cap - edges [id].flow < 1)
      continue;
    long long tr = dfs (u, std::min (pushed, edges [id].cap - edges [id].flow));
    if (tr == 0)
      continue;
    edges [id].flow += tr;
    edges [id ^ 1].flow -= tr;
    return tr;
  }
  return 0;
}

long long flow () {
  long long f = 0;
  while (true) {
    std::fill (level.begin (), level.end (), -1);
    level [s] = 0;
    q.push (s);
    if (!bfs ())
      break;
    std::fill (ptr.begin (), ptr.end (), 0);
    while (long long pushed = dfs (s, flow_inf)) {
      f += pushed;
    }
  }
  return f;
}


void input () {
	while (scanf ("%d", &n) != EOF) {
		scanf ("%d%d", &m, &p);
		arr.clear ();
		arr.resize (n);
		std::cin.ignore ();
		for (int i = 0; i < n; i++) {
			std::string a; std::cin >> a;
			arr [i].push_back (a);
		}
		solve ();
	}
}

void solve () {
	n += 2;
	dinic (n, 0, n - 1);

	memset (ins, 0, sizeof ins);
	for (int i = 0; i < arr.size (); i++) {
		for (int j = 0; j < arr [i].size (); j++) {
			if (!ins [i][j] && i > 0 && arr [i - 1][j] != '~') {
				if (arr [i][j] == '.' || arr [i][j] == '*') {
					ins [i][j] = 1;
				}
			}
		}
	}
}

int main () {
	return 0;
}
