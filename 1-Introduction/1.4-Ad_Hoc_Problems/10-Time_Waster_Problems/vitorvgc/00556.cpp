#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline int left(int d)  { return (d + 3) % 4; }
inline int right(int d) { return (d + 1) % 4; }
inline int back(int d)  { return (d + 2) % 4; } 
inline pii pos(pii p, int d) { return pii(p.x + dx[d], p.y + dy[d]); }

int main() {
    int n, m;
    while(cin >> n >> m && n|m) {

        string grid[n+5];
        int vis[n+5][m+5];
        
        memset(vis, 0, sizeof vis);

        string wall;
        for(int i = 0; i < m+2; ++i)
            wall += "1";

        grid[0] = grid[n+1] = wall;
        for(int i = 1; i <= n; ++i) {
            cin >> grid[i];
            grid[i] = "1" + grid[i] + "1";
        }
        
        int dir = 0;
        pii p = {1, n};

        do {
            ++vis[p.y][p.x];

            pii pf = pos(p, dir);
            pii pl = pos(p, left(dir));
            pii pr = pos(p, right(dir));
            pii pb = pos(p, back(dir));

            if(grid[pr.y][pr.x] == '0')
                p = pr, dir = right(dir);
            else if(grid[pf.y][pf.x] == '0')
                p = pf;
            else if(grid[pl.y][pl.x] == '0')
                p = pl, dir = left(dir);
            else
                p = pb, dir = back(dir);

        } while(p != pii(1, n));

        int ans[5] = {0};
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(grid[i][j] == '0')
                    ++ans[vis[i][j]];

        for(int i = 0; i < 5; ++i)
            printf("%3d", ans[i]);
        printf("\n");
    }
    return 0;
}
