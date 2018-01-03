#include <bits/stdc++.h>

using namespace std;

int main () {

    int t, n, m;
    char c;

    for (cin >> t; t > 0; t--) {
        cin >> c >> n >> m;

        int res = 1, KRes = ((n + 1) / 2) * ((m + 1) / 2);

        if (c == 'r' || c == 'Q') { res = min(n, m); }
        else if (c == 'k') { res = KRes + ((m / 2) * (n / 2)); }
        else { res = KRes; }
        cout << res << "\n";
    }
    return 0;
}