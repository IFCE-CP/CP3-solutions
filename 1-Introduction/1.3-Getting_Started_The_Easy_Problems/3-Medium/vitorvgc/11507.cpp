#include <bits/stdc++.h>

using namespace std;

string d[] = {"+y", "-y", "+z", "-z", "+x", "-x"};

int transition[6][4] = {
	{5, 4, 0, 0},
	{4, 5, 1, 1},
	{2, 2, 5, 4},
	{3, 3, 4, 5},
	{0, 1, 2, 3},
	{1, 0, 3, 2}
};

int index(string s) {
	for(int i = 0; i < 6; ++i)
		if(d[i] == s)
			return i;
	return -1;
}

int main() {
	int n;
	while(scanf("%d", &n) && n) {
		string s;
		int cur = 4;
		while(--n) {
			cin >> s;
			if(s == "No") continue;
			cur = transition[cur][index(s)];
		}
		cout << d[cur] << '\n';
	}
	return 0;
}
