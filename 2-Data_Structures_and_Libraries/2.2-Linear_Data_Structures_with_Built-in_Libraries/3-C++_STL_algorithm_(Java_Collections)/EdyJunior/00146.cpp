#include <bits/stdc++.h>

using namespace std;

int main () {
	
	string line;
	while (cin >> line && line != "#") {
		if (next_permutation(line.begin(), line.end())) { cout << line << "\n"; }
		else { printf("No Successor\n"); }
	}
	return 0;
}