#include <bits/stdc++.h>

using namespace std;

int main() {

	int p[5], s[5];

	while(scanf("%d %d %d %d %d", &s[0], &s[1], &s[2], &p[0], &p[1]) && s[0]) {
		sort(s, s + 3);
		sort(p, p + 2);
		int c[60];

		for(int i = 0; i < 53; i++) { c[i] = 0; }
		for(int i = 0; i < 3; i++) { c[s[i]] = 1; }
		for(int i = 0; i < 2; i++) { c[p[i]] = 1; }

		int vic = 0;
		bool lost = false;

		for (int i = 1; i >= 0; i--) {
			lost = false;
			for (int j = 0; j < 3 && !lost; j++) {
				if (s[j] > p[i] && c[s[j]] != 2) {
					c[s[j]] = c[p[i]] = 2;
					lost = true;
				}
			}
			if (!lost) { 
				vic++;
				for(int j = 0; j < 3; j++) { 
					if (c[s[j]] == 1) { 
						c[p[i]] = c[s[j]] = 2;
						break;
					}
				}
			}
		}
		if (!vic) { cout << "-1\n"; }
		else if (vic == 1) {
			int over = 0;
			for(int i = 0; i < 3; i++) { 
				if (c[s[i]] == 1) { 
					over = s[i]; 
					break;
				}
			}
			int i = over;
			for (; i < 53; ++i) {
				if (!c[i]) {
					cout << i << "\n";
					break;
				}
			}
			if (i == 53) { cout << "-1\n"; }
		} else {
			for (int i = 1; i < 53; i++) {
				if (!c[i]) {
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}