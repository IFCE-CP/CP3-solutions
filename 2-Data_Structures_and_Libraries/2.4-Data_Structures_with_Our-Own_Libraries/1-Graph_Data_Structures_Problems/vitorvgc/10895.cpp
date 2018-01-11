#include <bits/stdc++.h>

#define value first
#define index second

#define MAX 10100

using namespace std;

typedef pair<int, int> pii;

vector<pii> g[MAX];

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF) {
        
        for(int i = 1; i <= max(m, n); ++i)
            g[i].clear();

        for(int i = 1; i <= m; ++i) {
            int q, x;
            scanf("%d", &q);
            vector<int> idx(q);
            for(int j = 0; j < q; ++j)
                scanf("%d", &idx[j]);
            for(int j = 0; j < q; ++j) {
                scanf("%d", &x);
                g[idx[j]].push_back(pii(x, i));
            }
        }

        printf("%d %d\n", n, m);
        for(int i = 1; i <= n; ++i) {
            
            printf("%d", g[i].size());
            for(auto x : g[i])
                printf(" %d", x.index);
            printf("\n");

            if(g[i].size()) {
                printf("%d", g[i][0].value);
                for(unsigned j = 1; j < g[i].size(); ++j)
                    printf(" %d", g[i][j].value);
            }
            printf("\n");
        }
    }
    return 0;
}
