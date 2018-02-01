#include <bits/stdc++.h>

using namespace std;

vector<int> g[30];
int degree[30];
bool isVertice[30], vis[30];

inline int id(char c) { return c - 'A'; }

void dfs(int v) {
    if(vis[v]) return;
    vis[v] = true;
    for(auto w : g[v]) dfs(w);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    for(cin >> t; t--; ) {

        for(auto& v : g) v.clear();
        memset(degree, 0, sizeof degree);
        memset(isVertice, 0, sizeof isVertice);
        memset(vis, 0, sizeof vis);

        string s;
        while(cin >> s && s[0] != '*') {
            char u, v;
            sscanf(s.c_str(), "(%c,%c)", &u, &v);
            g[id(u)].push_back(id(v));
            g[id(v)].push_back(id(u));
            ++degree[id(u)];
            ++degree[id(v)];
        }
        cin >> s;
        for(unsigned i = 0; i < s.length(); i += 2)
            isVertice[id(s[i])] = true;
        
        int acorns = 0;
        for(int i = 0; i < 30; ++i)
            acorns += (isVertice[i] && degree[i] == 0);

        int trees = 0;
        for(int i = 0; i < 30; ++i)
            if(isVertice[i] && !vis[i])
                dfs(i), ++trees;

        cout << "There are " << trees - acorns << " tree(s) and " << acorns << " acorn(s).\n";
    }
    return 0;
}
