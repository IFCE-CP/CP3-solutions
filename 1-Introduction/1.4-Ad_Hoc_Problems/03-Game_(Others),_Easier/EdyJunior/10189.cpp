#include <bits/stdc++.h>

using namespace std;

int vx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int vy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {

	int n, m, f = 1;
	while (cin >> n >> m && n + m) {
		if (f > 1) { cout << "\n"; }
		getchar();

		string s[n];
		for (int i = 0; i < n; i++) { getline(cin, s[i]); }

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] != '.') { continue; }
				int count = 0;

				for (int k = 0; k < 8; k++) {
					if (i + vy[k] >= 0 && i + vy[k] < n &&
						j + vx[k] >= 0 && j + vx[k] < m &&
						s[i + vy[k]][j + vx[k]] == '*') {
						count++;
					}
				}
				s[i][j] = count + 48;
			}
		}
		printf("Field #%d:\n", f++);
		for (int i = 0; i < n; i++) { cout << s[i] << "\n"; }
	}
	return 0;
}