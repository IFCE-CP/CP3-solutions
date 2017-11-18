#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int n, m, ind = 1;
	while (cin >> n >> m && n + m) {
		if (ind > 1) { cout << "\n"; }

		string s, bestS;
		double p = 0.0, bestC = 0.0, bestP = 0.0;
		int r;

		getchar();

		for (int i = 0; i < n; i++) {
			getline(cin, s);
		}

		for (int i = 0; i < m; i++) {
			getline(cin, s);
			cin >> p >> r;

			getchar();

			string s2;
			for (int j = 0; j < r; j++) {
				getline(cin, s2);
			}
			double comp = 1.0 * r / n;
			if (comp > bestC || (comp == bestC && p < bestP)) { 
				bestC = 1.0 * r / n; 
				bestS = s;
				bestP = p;
			}
		}

		cout << "RFP #" << ind++ << "\n" << bestS << "\n";
	}

	return 0;
}