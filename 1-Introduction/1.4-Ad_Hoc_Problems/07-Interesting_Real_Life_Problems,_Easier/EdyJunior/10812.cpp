#include <bits/stdc++.h>

using namespace std;

int main () {
	
	long long d, s, a, b, t;

	for (cin >> t; t > 0; t--) {
		cin >> s >> d;
		a = (s + d) / 2;
		b = s - a;

		if (a - b == d && a >=0 && b >= 0) {
			cout << max(a, b) << " " << min(a, b) << "\n";
		} else {
			b = (s + d) / 2;
			a = s - b;
			if (b - a == d && b >= 0 && a >= 0) {
				cout << max(a, b) << " " << min(a, b) << "\n";
			} else { cout << "impossible\n"; }
		}
	}

	return 0;
}