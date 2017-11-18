#include <iostream>

using namespace std;

int main () {
	
	int k, n, m;

	while (cin >> k && k) {
		cin >> n >> m;
		for (int i = 0, x, y; i < k; i++) {
			cin >> x >> y;
			if (n == x || m == y) { cout << "divisa\n"; }
			else if (x < n && y > m) { cout << "NO\n"; }
			else if (x > n && y > m) { cout << "NE\n"; }
			else if (x > n && y < m) { cout << "SE\n"; }
			else if (x < n && y < m) { cout << "SO\n"; }
		}
	}
	return 0;
}