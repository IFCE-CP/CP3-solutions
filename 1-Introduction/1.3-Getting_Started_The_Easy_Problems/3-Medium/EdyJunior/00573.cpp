#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	double h, u, d, f;

	while (cin >> h >> u >> d >> f && h > 0.0) {
		int res = 1;
		double curH = 0.0, u2 = u, s = u * f/100.0;

		while (1) {

			curH += u2;
			u2 -= s;

			if (u2 < 0.0) { u2 = 0.0; }
			if (curH > h) {
				cout << "success on day " << res << "\n";
				break;
			}
			
			curH -= d;
			if (curH < 0.0) {
				cout << "failure on day " << res << "\n";
				break;
			}
			res++;
		}
	}
	return 0;
}