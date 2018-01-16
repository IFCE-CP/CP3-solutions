#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int pages;

	while (cin >> pages && pages) {
		int sPage = 1, fPage, sheets, cSheet = 1;
		bool isFront = true;
		sheets = pages / 4 + (pages % 4 ? 1 : 0);
		fPage = sheets * 4;
		printf("Printing order for %d pages:\n", pages);
		for (int i = 0; i < sheets * 4; i++) {
			int n1 = isFront ? fPage : sPage;
			int n2 = isFront ? sPage : fPage;

			if (fPage > sPage && (n1 <= pages || n2 <= pages)) {
				printf("Sheet %d, %s: ", cSheet, isFront ? "front" : "back ");
				if (n1 > pages) { printf("Blank, %d\n", n2); }
				else if (n2 > pages) { printf("%d, Blank\n", n1); }
				else { printf("%d, %d\n", n1, n2); }
			}
			fPage--;
			sPage++;

			if (!isFront) {
				isFront = true;
				cSheet++;
			} else { isFront = false; }
		}
	}
	return 0;
}