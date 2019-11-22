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

const long long flow_inf = 0x3f3f3f3f3f3f3f3f;
int n, pos;
int s, t;

vf edges;
vvi adj;
vi level, ptr;
qi q;

// init
void dinic (int n1, int s1, int t1) {
	n = n1; s = s1; t = t1;
	adj.clear ();
	level.clear ();
	ptr.clear ();
	adj.resize (n);
	level.resize (n);
	ptr.resize (n);
}

// add an edge to the residual graph
void add_edge (int v, int u, long long cap) {
	// add an edge V -> U with CAP
	// add an back-edge U -> V with 0
	edges.push_back (flow_edge (v, u, cap));
	edges.push_back (flow_edge (u, v, 0));
	// undirected graph which represents
	// the residual graph without any capacity
	adj [v].push_back (pos);
	adj [u].push_back (pos + 1);
	pos += 2;
}

bool bfs () {
	while (!q.empty ()) {
		int v = q.front ();
		q.pop ();
		for (int id : adj [v]) {
			// if there is no capacity left and
			// the vertex is already visited just continue
			if (edges [id].cap - edges [id].flow < 1)
				continue;
			if (level [edges [id].u] != -1)
				continue;
			// normal bfs
			level [edges [id].u] = level [v] + 1;
			q.push (edges [id].u);
		}
	}
	// return true if the sink T is reached
	return level [t] != -1;
}

long long dfs (int v, long long pushed) {
	if (pushed == 0)
		return 0;
	if (v == t)
		return pushed;

	// for all neightbors of v
	for (int &cid = ptr [v]; cid < (int)adj [v].size (); cid++) {
		// ID  is the id of edge which connects V -> U
		int id = adj [v][cid];
		// u is the back-edge of V -> U
		int u = edges [id].u;

		// if V -> U isnt on the bfs spanning tree
		// or it doesnt have capacity left just continue
		if (level [v] + 1 != level [u] || edges [id].cap - edges [id].flow < 1)
			continue;
		// find the min_edge capacity on the bfs spanning tree using dfs
		long long tr = dfs (u, std::min (pushed, edges [id].cap - edges [id].flow));
		// if there isnt flow left, continue
		if (tr == 0)
			continue;
		// else update the flow residual graph
		edges [id].flow += tr;
		edges [id ^ 1].flow -= tr;
		// return TR
		return tr;
	}
	// return 0 if there isnt capacity left
	return 0;
}

long long flow () {
	long long f = 0;
	while (true) {
		// all level are -1
		std::fill (level.begin (), level.end (), -1);
		// source level is 0
		level [s] = 0;
		q.push (s);
		if (!bfs ())
			break;
		// all ptr are 0
		std::fill (ptr.begin (), ptr.end (), 0);
		// pushed will be the min-edge or max-flow in the
		// bfs spanning tree, which was found by the dfs
		while (long long pushed = dfs (s, flow_inf)) {
			f += pushed;
		}
	}
	return f;
}

void input () {
}

void solve () {
}


int main () {
	// necessary to add the (S)ource and the (T)sink using add_edge ();
	return 0;
}
