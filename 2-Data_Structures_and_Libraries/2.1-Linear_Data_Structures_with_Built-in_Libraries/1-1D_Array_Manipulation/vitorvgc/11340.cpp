#include <bits/stdc++.h>

using namespace std;

int value[500];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, k;
    string s;
    for(cin >> t; t--; ) {
        memset(value, 0, sizeof value);
        for(cin >> k, cin.ignore(); k--; ) {
            char c;
            int v;
            cin >> c >> v; cin.ignore();
            value[c + 128] = v;
        }
        long long ans = 0;
        for(cin >> n, cin.ignore(); n--; ) {
            getline(cin, s);
            for(auto c : s) ans += value[c + 128];
        }
        printf("%lld.%02lld$\n", ans / 100, ans % 100);
    }
    return 0;
}
