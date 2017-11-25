#include <bits/stdc++.h>

#define MAX 110

using namespace std;

int q[MAX][MAX];
char l[MAX][MAX];

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    int n, m, caso = 0;
    while(scanf("%d %d", &n, &m) && n|m) {
        
        for(int i = 1; i <= n; ++i) {
            getchar();
            for(int j = 1; j <= m; ++j) {
                scanf("%c", &l[i][j]);
                q[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(l[i][j] == '*')
                    for(int k = 0; k < 8; ++k) {
                        int x = j + dx[k];
                        int y = i + dy[k];
                        ++q[y][x];
                    }
        
        if(caso > 0) printf("\n");
        printf("Field #%d:\n", ++caso);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j)
                printf("%c", l[i][j] == '*' ? '*' : q[i][j] + 48);
            printf("\n");
        }
    }
}
