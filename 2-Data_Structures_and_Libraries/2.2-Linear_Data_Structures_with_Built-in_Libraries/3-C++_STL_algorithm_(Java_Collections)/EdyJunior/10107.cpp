#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
	
	ll array[10005], size = 0;
	while (scanf("%lld", &array[size++]) != EOF) {
		nth_element(array, array + size / 2, array + size);
		if (size & 1) { printf("%lld\n", array[size / 2]); }
		else {
			nth_element(array, -1 + array + size / 2, array + size);
			ll a = array[size / 2], b = array[-1 + size / 2];
			printf("%lld\n", (a + b) / 2);
		}
	}
	return 0;
}