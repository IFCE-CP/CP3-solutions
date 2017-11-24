#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;

	cin >> n;
	getchar();

	for (int t = 1; t <= n; t++) {
		list<string> lis;
		queue<string> hand;
		string s;
		int y = 0;

		for (int i = 0; i < 27; ++i) {
			cin >> s;
			lis.push_back(s);
		}
		for (int i = 0; i < 25; ++i) {
			cin >> s;
			hand.push(s);
		}
		for (int i = 0; i < 3; i++) {
			string top = lis.back();
			lis.pop_back();
			int x = ((top[0] >= 48 && top[0] <= 57) ? top[0] - 48 : 10);
			y += x;
			for (int j = 0; j < 10 - x; j++) { lis.pop_back(); }
		}
		int count = 0;
		for (int i = 0; i < hand.size(); i++) {
			lis.push_back(hand.front());
			hand.pop();
		}
		list<string>::iterator it;
		for (it = lis.begin(); count < y - 1; it++, count++);

		string res = *it;
		printf("Case %d: %s\n", t, res.c_str());
	}
	return 0;
}