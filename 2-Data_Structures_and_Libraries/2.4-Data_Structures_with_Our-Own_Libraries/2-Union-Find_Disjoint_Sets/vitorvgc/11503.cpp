#include <bits/stdc++.h>

using namespace std;

class UnionFind {

private:
    vector<int> p, rnk, setSize;

public:
    
    UnionFind(int n) {
        p = rnk = vector<int>(n, 0);
        setSize = vector<int>(n, 1);
        for(int i = 0; i < n; ++i)
            p[i] = i;
    }

    int findSet(int v) {
        return p[v] == v ? v : p[v] = findSet(p[v]);
    }

    void unionSet(int v, int w) {
        v = findSet(v);
        w = findSet(w);
        if(v == w) return;
        rnk[v] < rnk[w] ? p[v] = w : p[w] = v;
        if(rnk[v] == rnk[w]) ++rnk[v];
        setSize[v] = setSize[w] = setSize[v] + setSize[w];
    }

    int sizeOfSet(int v) {
        return setSize[findSet(v)];
    }
};

unordered_map<string, int> mp;

int id(string s) {
    if(mp.find(s) == mp.end())
        mp[s] = mp.size();
    return mp[s];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    for(cin >> t; t--; ) {
        int n;
        cin >> n;
        UnionFind uf(2*n+5);
        mp.clear();
        while(n--) {
            string a, b;
            cin >> a >> b;
            uf.unionSet(id(a), id(b));
            cout << uf.sizeOfSet(id(a)) << "\n";
        }
    }
    return 0;
}
