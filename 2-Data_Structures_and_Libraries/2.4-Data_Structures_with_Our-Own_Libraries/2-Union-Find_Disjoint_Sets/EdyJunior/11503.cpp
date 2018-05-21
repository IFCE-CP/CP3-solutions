#include <bits/stdc++.h>

using namespace std;

map<string, string> p;
map<string, int> r;

string Find(string a) {
	return p[a] = p[a] == a ? a : Find(p[a]);
}

void Union(string a, string b) {

	string x = Find(a);
	string y = Find(b);

	if (x != y) {
		if (r[x] > r[y]) {
			p[y] = x;
			r[x] += r[y];
		} else {
			p[x] = y;
			r[y] += r[x];
		}
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(0);
	int t, n;
	for (cin >> t; t > 0; t--) {
		p.clear(), r.clear();
		for (cin >> n; n > 0; n--) {
			string a, b;
			cin >> a >> b;
			if (p.find(a) == p.end()) {
				p[a] = a;
				r[a] = 1;
			}
			if (p.find(b) == p.end()) {
				p[b] = b;
				r[b] = 1;
			}
			Union(a, b);
			cout << r[Find(a)] << "\n";
		}
	}
	return 0;
}