#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string line;
	
	while (getline(cin, line)) {
		int size 	  = line.size();
		int points    = 0;
		int pointsB   = 0;
		int bidSuit   = 0;
		int mostCards = 0;
		int suits[]   = { 0, 0, 0, 0 };
		int kings[]   = { 0, 0, 0, 0 };
		int queens[]  = { 0, 0, 0, 0 };
		int jacks[]   = { 0, 0, 0, 0 };
		bool stop[]   = { false, false, false, false };
		
		string table = "SHDC";

		for (int i = 0; i < size; i += 3) {
			char rank = line[i];
			int suit;
			for (int j = 0; j < 4; ++j) { 
				if (table[j] == line[i + 1]) { suit = j; }
			}
			switch(rank) {
				case 'A':
					points  += 4;
					pointsB += 4;
					stop[suit] = true;
					break;
				case 'K':
					points  += 3;
					pointsB += 3;
					kings[suit]++;
					break;
				case 'Q':
					points  += 2;
					pointsB += 2;
					queens[suit]++;
					break;
				case 'J':
					points  += 1;
					pointsB += 1;
					jacks[suit]++;
					break;
			}
			suits[suit]++;
			if (suits[suit] > mostCards || (suits[suit] == mostCards && suit < bidSuit)) {
				mostCards = suits[suit];
				bidSuit   = suit;
			}
		}
		for (int i = 0; i < 4; ++i) {
			if (kings[i] ) { 
				points  -= (suits[i] == 1 ? 1 : 0);
				pointsB -= (suits[i] == 1 ? 1 : 0); 
			}
			if (queens[i]) { 
				points  -= (suits[i] <= 2 ? 1 : 0); 
				pointsB -= (suits[i] <= 2 ? 1 : 0); 
			}
			if (jacks[i] ) { 
				points  -= (suits[i] <= 3 ? 1 : 0);
				pointsB -= (suits[i] <= 3 ? 1 : 0);
			}
			if (suits[i] == 2) { points += 1; }
			if (suits[i] == 1) { points += 2; }
			if (suits[i] == 0) { points += 2; }

			if (suits[i] >= 2) {
				if (kings[i] || (queens[i] && suits[i] >= 3)) { stop[i] = true; }
			}
		}
		bool allSuitsStoped = true;
		for (int i = 0; i < 4; ++i) { allSuitsStoped = allSuitsStoped && stop[i]; }

		if (points < 14) { printf("PASS\n"); }
		else if (pointsB > 15 && allSuitsStoped) { printf("BID NO-TRUMP\n"); }
		else { printf("BID %c\n", table[bidSuit]); }
	}
	return 0;
}