#include <bits/stdc++.h>

#define MAX 110

using namespace std;

vector<int> g[MAX];
int n;
int color[MAX];
vector<int> ans, cur;

bool canBeBlack(int v) {
    for(auto w : g[v])
        if(color[w] == 1)
            return false;
    return true;
}

void solve(int v) {
    
    if(v > n) {
        if(cur.size() > ans.size())
            ans = cur;
        return;
    }

    if(canBeBlack(v)) {
        color[v] = 1;
        cur.push_back(v);
        solve(v + 1);
        color[v] = 0;
        cur.pop_back();
    }
    solve(v + 1);
}

int main() {

    int t, m;
    for(scanf("%d", &t); t--; ) {
        scanf("%d %d", &n, &m);

        for(int i = 0; i <= n; ++i)
            g[i].clear();
        while(m--) {
            int v, w;
            scanf("%d %d", &v, &w);
            g[v].push_back(w);
            g[w].push_back(v);
        }

        memset(color, 0, sizeof color);
        cur.clear();
        ans.clear();
        solve(1);

        printf("%lu\n%d", ans.size(), ans[0]);
        for(int i = 1; i < ans.size(); ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }

    return 0;
}
