#include <bits/stdc++.h>

#define freq first
#define value second

#define MAX 100100

using namespace std;

typedef pair<int, int> pii;

struct Node {
    
    pii mx, left, right;

    Node() {}
    Node(pii p): mx(p), left(p), right(p) {}
    Node(pii mx, pii left, pii right): mx(mx), left(left), right(right) {}

    friend Node operator+(Node l, Node r);
};

Node tree[4*MAX];
int v[MAX];

Node operator+(Node l, Node r) {

    if(l.mx.freq <= 0) return r;
    if(r.mx.freq <= 0) return l;

    Node ans;

    ans.mx = (l.mx.freq > r.mx.freq ? l.mx : r.mx);

    if(l.right.value == r.left.value) {
        pii middleRange = pii(l.right.freq + r.left.freq, l.right.value);
        if(middleRange.freq > ans.mx.freq)
            ans.mx = middleRange;

        ans.left = (l.left.value == l.right.value ? middleRange : l.left);
        ans.right = (r.left.value == r.right.value ? middleRange : r.right);
        return ans;
    }
        
    ans.left = l.left;
    ans.right = r.right;
    return ans;
}

void build(int i, int l, int r) {
    
    if(l == r) {
        tree[i] = Node(pii(1, v[l]));
        return;
    }
    
    int m = (l + r) / 2;
    build(2*i, l, m);
    build(2*i + 1, m + 1, r);
    
    tree[i] = tree[2*i] + tree[2*i + 1];
}

Node query(int i, int l, int r, int a, int b) {
    
    if(l > b || r < a) return Node(pii(0,0));

    if(l >= a && r <= b) return tree[i];

    int m = (l + r) / 2;
    return query(2*i, l, m, a, b) + query(2*i + 1, m + 1, r, a, b);
}

int main() {
    int n, q;
    while(scanf("%d", &n) && n) {
        scanf("%d", &q);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &v[i]);

        build(1, 1, n);
        while(q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", query(1, 1, n, a, b).mx.freq);
       }
    }
    return 0;
}
