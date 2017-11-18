#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int n, k, h;
	cin >> n;
	for(int i = 1; i <= n; i++) {

		int fast = -1;
		for (cin >> k; k > 0; k--) {
			cin >> h;
			if (h > fast) { fast = h; }
		}
		printf("Case %d: %d\n", i, fast);
	}

	return 0;
}