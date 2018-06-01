#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	getchar();
	getchar();
	for (int j = 0; j < n; j++) {
		if (j) { printf("\n"); }
		string s;
		map<string, int> m;
		int tot = 0;
		while (getline(cin, s) && s != "") {
			m[s]++;
			tot++;
		}
		vector<pair<string, double>> vp;
		for (auto kv : m)
			vp.push_back({kv.first, (double) kv.second / tot});
		sort(vp.begin(), vp.end());
		for (int i = 0; i < vp.size(); i++)
			printf("%s %.4lf\n", vp[i].first.c_str(), 100 * vp[i].second);
	}
	return 0;
}