#include <bits/stdc++.h>

#define MAX 1024100

using namespace std;

int tree[4*MAX], lazy[4*MAX];
string s;

void build(int i, int l, int r) {
    
    lazy[i] = 0;
    if(l == r) {
        tree[i] = s[l] - '0';
        return;
    }

    int m = (l + r) / 2;
    build(2*i, l, m);
    build(2*i + 1, m + 1, r);

    tree[i] = tree[2*i] + tree[2*i + 1];
}

char updatedLazy(char oldMode, char newMode) {

    if(!oldMode || newMode != 'I') return newMode;

    if(oldMode == 'F') return 'E';
    if(oldMode == 'E') return 'F';
    return 0;
}

void propagate(int i, int l, int r) {
    
    if(!lazy[i]) return;

    if(lazy[i] == 'F') tree[i] = r - l + 1;
    else if(lazy[i] == 'E') tree[i] = 0;
    else tree[i] = r - l + 1 - tree[i];
    
    if(l != r) {
        lazy[2*i] = updatedLazy(lazy[2*i], lazy[i]);
        lazy[2*i + 1] = updatedLazy(lazy[2*i + 1], lazy[i]);
    }
    lazy[i] = 0;
}

void update(int i, int l, int r, int a, int b, char mode) {

    propagate(i, l, r);

    if(l > b || r < a) return;

    if(l >= a && r <= b) {
        lazy[i] = updatedLazy(lazy[i], mode);
        propagate(i, l, r);
        return;
    }

    int m = (l + r) / 2;
    update(2*i, l, m, a, b, mode);
    update(2*i + 1, m + 1, r, a, b, mode);

    tree[i] = tree[2*i] + tree[2*i + 1];
}

int query(int i, int l, int r, int a, int b) {

    if(l > b || r < a) return 0;

    propagate(i, l, r);

    if(l >= a && r <= b) return tree[i];

    int m = (l + r) / 2;
    return query(2*i, l, m, a, b) + query(2*i + 1, m + 1, r, a, b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for(int caso = 1; caso <= t; ++caso) {
        int n, m, q = 1;
        s = "";
        for(cin >> m; m--; ) {
            int x;
            string aux;
            for(cin >> x >> aux; x--; )
                s += aux;
        }
        n = s.length();
        build(1, 0, n-1);

        cout << "Case " << caso << ":\n";
        for(cin >> m, cin.ignore(); m--; ) {
            char mode;
            int a, b; 
            cin >> mode >> a >> b; cin.ignore();

            if(mode == 'S')
                cout << "Q" << q++ << ": " << query(1, 0, n-1, a, b) << "\n";
            else
                update(1, 0, n-1, a, b, mode);
        }
    }
}
