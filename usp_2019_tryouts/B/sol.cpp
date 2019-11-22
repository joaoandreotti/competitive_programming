#include <bits/stdc++.h>

#define DOLLAR 0
#define COLUMN 1
#define PIPE 2
#define OPEN 3
#define CLOSE 4
#define INT 5

std::vector<int> tokens;
int pos, look_ahead;

void m ();
void m_1 ();
void p ();
void p_1 ();
void t ();

void match (int a) {
	//printf ("lk: %d\n", look_ahead);
	if (look_ahead == a)
		look_ahead = tokens [pos++];
	else {
		std::cout << "NO\n";
		exit (0);
	}
}

void m () {
	//printf ("m, %d\n", look_ahead);
	if (look_ahead == OPEN) {
		match (OPEN);
		p ();
		m_1 ();
	}
	else if (look_ahead == INT) {
		p ();
		m_1 ();
	}
	else if (look_ahead == DOLLAR) {
		match (DOLLAR);
		match (PIPE);
		p ();
		m_1 ();
	}
	else if (look_ahead == PIPE) {
		match (PIPE);
		m ();
		m_1 ();
	}
	else {
		puts ("NO");
		exit (0);
	}
}

void m_1 () {
	//printf ("m_1, %d\n", look_ahead);
	if (look_ahead == PIPE) {
		match (PIPE);
		m ();
		m_1 ();
	}
}

void p () {
	//printf ("p, %d\n", look_ahead);
	t ();
	p_1 ();
}

void p_1 () {
	//printf ("p_1, %d\n", look_ahead);
	if (look_ahead == COLUMN) {
		match (COLUMN);
		t ();
		p_1 ();
	}
}

void t () {
	//printf ("t, %d\n", look_ahead);
	if (look_ahead == OPEN) {
		match (OPEN);
		m ();
		match (CLOSE);
	}
	else if (look_ahead == INT)
		match (INT);
	else {
		puts ("NO");
		exit (0);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string str;

	while (std::cin >> str) {

		if (str.size() == 1) {
			if (str[0] >= '0' && str[0] <= '9') {
				tokens.push_back(INT);
			} else if (str[0] == '$') {
				tokens.push_back(DOLLAR);
			} else if (str[0] == '|') {
				tokens.push_back(PIPE);
			} else if (str[0] == '{') {
				tokens.push_back(OPEN);
			} else if (str[0] == '}') {
				tokens.push_back(CLOSE);
			} else if (str[0] == ':') {
				tokens.push_back(COLUMN);
			} else {
				assert(false);
			}

		} else  {
			for (const char& c : str) {
				if (!(c >= '0' && c <= '9')) {
					return std::cout << "NO\n", 0;
				}
			}
			tokens.push_back(INT);
		}

	}
	look_ahead = tokens [pos++];
	//printf ("lk: %d\n", look_ahead);
	m ();
	std::cout << "YES\n";

	return 0;
}
