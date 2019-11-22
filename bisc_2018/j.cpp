#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>                                        

template <typename T>                                                           
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

void input ();
void solve ();

int n, p;
ordered_set <int> ans;

void input () {
	scanf ("%d%d", &n, &p);
	solve ();
}

void solve () {
	for (int i = 0; i < n; i++)
		ans.insert (i);

	int last = 0;
	while (ans.size () != 1) {
		last = (last + (p - 1)) % (int)ans.size ();
		ans.erase (ans.find_by_order (last));
	}
	printf ("%d\n", *ans.find_by_order (0) + 1);
}

int main () {
	input ();
	return 0;
}
