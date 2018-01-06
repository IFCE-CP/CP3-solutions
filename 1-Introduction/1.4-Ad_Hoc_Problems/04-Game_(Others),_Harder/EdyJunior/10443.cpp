#include <bits/stdc++.h>

using namespace std;

bool win(char a, char b) {

	if ((a == 'S' && b == 'P') ||
		(a == 'R' && b == 'S') ||
		(a == 'P' && b == 'R')) { return true; }
	return false;
}

int main() {

	int t;
	cin >> t;
	for (int j = 0; j < t; j++) {
		int r, c, n;
		cin >> r >> c >> n;
		getchar();

		char grid[r + 1][c + 1];
		for (int a = 0; a < r; a++) { 
			for (int b = 0; b < c; b++) { scanf("%c", &grid[a][b]); }
			getchar();
		}

		for (; n > 0; n--) {
			char res[r + 1][c + 1];

			for (int a = 0; a < r; a++) {
				for (int b = 0; b < c; b++) { res[a][b] = '*'; }
			}

			for (int a = 0; a < r; a++) {
				for (int b = 0; b < c; b++) {
					int x[] = { 1, 0, -1,  0 };
					int y[] = { 0, 1,  0, -1 };

					for (int i = 0; i < 4; i++) {
						int xp = b + x[i];
						int yp = a + y[i];

						char l1 = grid[a][b];
						char l2 = grid[yp][xp];

						if (xp >= 0 && xp < c && yp >= 0 && yp < r &&
							res[yp][xp] == '*' && win(l1, l2)) {
							res[yp][xp] = grid[a][b];
						}
					}
				}
			}
			for (int a = 0; a < r; a++) {
				for (int b = 0; b < c; b++) {
					char gAB = grid[a][b];
					char rAB = res[a][b];
					grid[a][b] = rAB != '*' ? rAB : gAB;
				}
			}
		}

		if (j) { cout << "\n"; }
		for (int a = 0; a < r; a++) { 
			for (int b = 0; b < c; b++) { cout << grid[a][b]; }
			cout << "\n";
		}
	}
	return 0;
}