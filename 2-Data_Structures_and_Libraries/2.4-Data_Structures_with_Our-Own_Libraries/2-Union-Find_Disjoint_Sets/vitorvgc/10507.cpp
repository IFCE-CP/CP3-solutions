#include <bits/stdc++.h>

using namespace std;

vector<int> g[30];
bool awake[30];

inline int id(char c) { return c - 'A'; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    string s;
    while(cin >> n >> m) {

        for(auto& v : g) v.clear();
        memset(awake, 0, sizeof awake);

        cin >> s;
        int q = s.length();
        for(auto c : s)
            awake[id(c)] = true;
        while(m--) {
            cin >> s;
            g[id(s[0])].push_back(id(s[1]));
            g[id(s[1])].push_back(id(s[0]));
        }

        int ans = 0;
        for(; q < n; ++ans) {
            vector<bool> willAwake(30, 0);

            for(int i = 0; i < 30; ++i)
                if(!awake[i]) {
                    int x = 0;
                    for(auto v : g[i])
                        x += awake[v];
                    willAwake[i] = (x >= 3);
                }

            int oldQ = q;
            for(int i = 0; i < 30; ++i)
                if(willAwake[i])
                    awake[i] = true, ++q;

            if(q == oldQ) break;
        }

        if(q < n) cout << "THIS BRAIN NEVER WAKES UP\n";
        else cout << "WAKE UP IN, " << ans << ", YEARS\n";
    } 
    return 0;
}
