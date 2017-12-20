#include <bits/stdc++.h>

#define MAX 110

using namespace std;

map<char, char> wins = {{'R', 'P'}, {'S', 'R'}, {'P', 'S'}};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m;

char g[MAX][MAX], g2[MAX][MAX];

inline bool inside(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int main() {
    int t, times;
    for(scanf("%d", &t); t--; ) {
        scanf("%d %d %d", &n, &m, &times);
        getchar();
        for(int i = 0; i < n; ++i)
            gets(g[i]);
        
        while(times--) {

            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j) {
                    char a = g[i][j];
                    char w = wins[a];
                    bool defeated = false;
                    for(int k = 0; k < 4 && !defeated; ++k) {
                        int x = j + dx[k];
                        int y = i + dy[k];
                        if(inside(x, y))
                            defeated |= (g[y][x] == w);
                    }
                    g2[i][j] = defeated ? w : a;
                }
            memcpy(g, g2, sizeof g);
        }

        for(int i = 0; i < n; ++i)
            printf("%s\n", g[i]);

        if(t) printf("\n");
    }

    return 0;
}
