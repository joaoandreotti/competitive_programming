#include <bits/stdc++.h>

#define x first
#define y second

void input ();
void solve ();

const int MAXN = 1e2;

typedef std::string sg;
typedef std::vector <sg> vsg;
typedef std::pair <int, int> pi;
typedef std::map <sg, sg> msg;
typedef std::vector <pi> vpi;

int wx [4] = {-1, 0, 1, 0};
int wy [4] = {0, 1, 0, -1};

int vis [MAXN][MAXN];

sg resp;

msg map;
vsg dir;
vpi path;

void dfs (pi p, sg l) {
	//printf ("{%d, %d} : %s\n", p.x, p.y, l.c_str ());
	if (vis [p.x][p.y])
		return;
	std::cout << l << std::endl;
	input ();
	if (resp == "EMPTY") {
		vis [p.x][p.y] = 1;
		for (int i = 0; i < dir.size (); i++)
			dfs (std::make_pair (p.x + wx [i], p.y + wy [i]), dir [i]);
		//printf ("{%d, %d} : %s\n", p.x, p.y, l.c_str ());
		std::cout << map [l] << std::endl;
		input ();
	}
}

void input () {
	std::cin >> resp;
}

void solve () {
	dir.push_back ("EAST");
	dir.push_back ("NORTH");
	dir.push_back ("WEST");
	dir.push_back ("SOUTH");
	map ["EAST"] = "WEST";
	map ["WEST"] = "EAST";
	map ["NORTH"] = "SOUTH";
	map ["SOUTH"] = "NORTH";

	path.push_back ({30, 30});
	for (int i = 0; i < dir.size (); i++) {
		pi l = path [path.size () - 1];
		dfs (std::make_pair (l.x + wx [i], l.y + wy [i]), dir [i]);
	}

	std::cout << "DONE" << std::endl;
}

int main () {
	solve ();
	return 0;
}
