#include <bits/stdc++.h>

using namespace std;

vector<int> g[1000100];

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {

        for(auto& v : g) v.clear();
        
        for(int i = 1, x; i <= n; ++i) {
            scanf("%d", &x);
            g[x].push_back(i);
        }

        while(m--) {
            int k, x;
            scanf("%d %d", &k, &x);
            printf("%d\n", k > (int)g[x].size() ? 0 : g[x][k-1]);
        }
    }
    return 0;
}
