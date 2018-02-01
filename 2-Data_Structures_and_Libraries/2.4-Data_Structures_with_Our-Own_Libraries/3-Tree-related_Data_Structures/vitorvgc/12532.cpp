#include <bits/stdc++.h>

#define MAX 100100

using namespace std;

int v[MAX], tree[4*MAX];

void build(int i, int l, int r) {
    
    if(l == r) {
        tree[i] = v[l];
        return;
    }

    int m = (l + r) / 2;
    build(2*i, l, m);
    build(2*i + 1, m + 1, r);

    tree[i] = tree[2*i] * tree[2*i + 1];
}

void update(int i, int l, int r, int ind) {

    if(l == r && l == ind) {
        tree[i] = v[ind];
        return;
    }

    if(l > ind || r < ind) return;

    int m = (l + r) / 2;
    update(2*i, l, m, ind);
    update(2*i + 1, m + 1, r, ind);

    tree[i] = tree[2*i] * tree[2*i + 1];
}

int query(int i, int l, int r, int a, int b) {

    if(l > b || r < a) return 1;

    if(l >= a && r <= b) return tree[i];

    int m = (l + r) / 2;
    return query(2*i, l, m, a, b) * query(2*i + 1, m + 1, r, a, b);
}

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF) {
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            if(v[i]) v[i] /= abs(v[i]);
        }

        build(1, 0, n-1);

        while(k--) {
            char op;
            int a, b;
            scanf(" %c %d %d", &op, &a, &b);
            if(op == 'C') {
                if(b) b /= abs(b);
                v[a-1] = b;
                update(1, 0, n-1, a-1);
            }
            else {
                int ans = query(1, 0, n-1, a-1, b-1);
                printf("%c", ans == 0 ? '0' : ans > 0 ? '+' : '-');
            }
        }
        printf("\n");
    }
}
