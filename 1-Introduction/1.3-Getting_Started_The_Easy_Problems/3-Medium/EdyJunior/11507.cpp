#include<bits/stdc++.h>

using namespace std;

int main() {

	string str, pos;
	int l;
	vector <vector<string>> s;
	string v[] = { "+x", "-x", "+y", "-y", "+z", "-z" };

	s.push_back({ "+y", "-y", "+z", "-z" });
	s.push_back({ "-y", "+y", "-z", "+z" });
	s.push_back({ "-x", "+x", "+y", "+y" });
	s.push_back({ "+x", "-x", "-y", "-y" });
	s.push_back({ "+z", "+z", "-x", "+x" });
	s.push_back({ "-z", "-z", "+x", "-x" });

	while (cin >> l && l) {
		pos = "+x";

		while (--l) {
			cin >> str;

			if (str == "No") { continue; }

			int ind = 0;
			for (int i = 0; i < 6; i++) 
				if (v[i] == str) { ind = i; }
			ind -= 2;
			int indC = 0;
			for (int i = 0; i < 6; i++) 
				if (v[i] == pos) { indC = i; }
			
			pos = s[indC][ind];
		}
		cout << pos << "\n";
	}
	return 0;
}