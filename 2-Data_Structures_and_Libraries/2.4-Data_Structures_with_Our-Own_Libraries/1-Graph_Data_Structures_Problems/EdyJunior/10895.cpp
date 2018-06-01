#include <bits/stdc++.h>

#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)

using namespace std;

typedef pair<int, int> pii;

int main() {

    int m, n;
    while (scanf("%d %d", &m, &n) != EOF && m + n) {
        vector<vector<pii>> g(n + 1);
        for (int i = 1, r, c; i <= m; i++) {
            scanf("%d", &r);
            int pos[r];
            for (int j = 0; j < r; j++)
                scanf("%d", &pos[j]);
            for (int j = 0; j < r; j++) {
                scanf("%d", &c);
                g[pos[j]].pb(mp(i, c));
            }
        }
        printf("%d %d\n", n, m);
        for (int i = 1; i <= n; i++) {
            printf("%lu", g[i].size());
            for (auto gi : g[i])
                printf(" %d", gi.F);
            printf("\n");
            for (int j = 0; j < g[i].size(); j++) {
                if (j)
                    printf(" ");
                printf("%d", g[i][j].S);
            }
            printf("\n");
        }
    }
    return 0;
}