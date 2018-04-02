#include <bits/stdc++.h>

using namespace std;

int l[25];
bool used[25];

void solve(int i, int s, vector<bool> &v, int &ans, int n, int mx) {
    
    if(i >= n) {
        if(s > ans) {
            ans = s;
            v = vector<bool>(used, used + n);
        }
        return;
    }

    if(s + l[i] <= mx) {
        used[i] = true;
        solve(i+1, s + l[i], v, ans, n, mx);
        used[i] = false;
    }

    solve(i+1, s, v, ans, n, mx);
}

int main() {
    int n, mx;
    while(scanf("%d %d", &mx, &n) != EOF) {

        for(int i = 0; i < n; ++i)
            scanf("%d", &l[i]);

        vector<bool> v(n);
        int ans = 0;
        memset(used, 0, sizeof used);
        solve(0, 0, v, ans, n, mx);

        for(int i = 0; i < n; ++i)
            if(v[i])
                printf("%d ", l[i]);
        printf("sum:%d\n", ans);
    }
    return 0;
}
