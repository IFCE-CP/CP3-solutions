#include <bits/stdc++.h>

using namespace std;

int main () {
	
	double h, m;
	while (scanf("%lf:%lf", &h, &m) != EOF && h + m) {
		double a2 = (m / 60) * 360;
		double a1 = (h / 12) * 360 + (a2 / 12);
		double res = min(abs(a1 - a2), min(a1, a2) + 360 - max(a1, a2));
		printf("%.3lf\n", res);
	}
	return 0;
}