#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int t;

	for (cin >> t; t > 0; t--) {
		int a, b, c;
		map<int, int> traps;
		bool gameover = false;

		cin >> a >> b >> c;

		int players[a + 1];
		for (int i = 0; i < a; ++i) { players[i] = 1; }

		for (int i = 0; i < b; i++) {
			int s, e;
			cin >> s >> e;
			traps[s] = e;
		}
		for (int i = 0, d; i < c; i++) {
			cin >> d;
			if (gameover || !a) { continue; }

			int pos = players[i % a];
			pos += d;
			players[i % a] = pos;
			if (pos >= 100) { 
				players[i % a] = 100;
				gameover = true;
			}

			if (!gameover && traps.find(pos) != traps.end()) {
				players[i % a] = traps[pos];
				if (players[i % a] >= 100) { 
					players[i % a] = 100;
					gameover = true;
				}
			}
		}
		for (int i = 0; i < a; ++i)
			printf("Position of player %d is %d.\n", i + 1, players[i]);
	}
	return 0;
}