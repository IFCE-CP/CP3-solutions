#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(4);
    int t;
    string s;
    for(cin >> t, cin.ignore(), getline(cin, s); t--; ) {

        mp.clear();
        int n = 0;
        while(getline(cin, s) && s.length())
            ++mp[s], ++n;

        for(auto it = mp.begin(); it != mp.end(); ++it)
            cout << it->first << " " << 100.0 * it->second / n << '\n';

        if(t) cout << '\n';
    }
    return 0;
}
