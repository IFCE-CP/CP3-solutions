#include <bits/stdc++.h>

using namespace std;

class UnionFind {
    
private:

    vector<int> p, rnk;

public:

    UnionFind(int n) {
        p = rnk = vector<int>(n+1, 0);
        for(int i = 1; i <= n; ++i)
            p[i] = i;
    }

    int findSet(int v) {
        return p[v] == v ? v : p[v] = findSet(p[v]);
    }

    void unionSet(int v, int w) {
        v = findSet(v);
        w = findSet(w);
        rnk[v] < rnk[w] ? p[v] = w : p[w] = v;
        if(rnk[v] == rnk[w]) ++rnk[v];
    }

    bool isSameSet(int v, int w) {
        return findSet(v) == findSet(w);
    }
}; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    string s;
    for(cin >> t, cin.ignore(), getline(cin, s); t--; ) {
        int n, a = 0, b = 0;
        cin >> n; cin.ignore();
        UnionFind uf(n);
        while(getline(cin, s) && s.length() > 2) {
            char op;
            int v, w;
            sscanf(s.c_str(), "%c %d %d", &op, &v, &w);
            if(op == 'c')
                uf.unionSet(v, w);
            else
                uf.isSameSet(v, w) ? ++a : ++b;
        }

        cout << a << "," << b << "\n";
        if(t) cout << "\n";
    }
    return 0;
}
