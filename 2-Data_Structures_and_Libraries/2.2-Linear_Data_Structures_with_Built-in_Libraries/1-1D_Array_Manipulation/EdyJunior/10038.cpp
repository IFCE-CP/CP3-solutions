#include <bits/stdc++.h>

using namespace std;

int main () {
	
    int n;
    while (cin >> n) {
        int last = 0;
        set<int> s;

        for (int i = 0, k; i < n; i++) {
            cin >> k;
            int diff = abs(last - k);
            if (i && diff < n && diff) {
                s.insert(diff);
            }
            last = k;
        }
        printf("%s\n", s.size() == n - 1 ? "Jolly" : "Not jolly");
    }
    return 0;
}