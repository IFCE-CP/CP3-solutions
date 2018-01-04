#include <bits/stdc++.h>

#define MAX 110

using namespace std;

char grid[MAX][MAX], m[MAX][MAX], aux[MAX][MAX];

void rotate(int n) {

    for(int i = 0, j2 = n-1; i < n; ++i, --j2)
        for(int j = 0; j < n; ++j)
            aux[j][j2] = m[i][j];
    memcpy(m, aux, sizeof m);
}

int intersections(int n, int N) {

    int ans = 0;
    for(int i = 0; i <= N-n; ++i)
        for(int j = 0; j <= N-n; ++j) {
            
            bool ok = true;
            for(int i2 = 0; i2 < n && ok; ++i2)
                for(int j2 = 0; j2 < n && ok; ++j2)
                    ok &= (m[i2][j2] == grid[i+i2][j+j2]);
            ans += ok;
        }
    return ans;
}

int main() {
    int N, n;
    while(scanf("%d %d", &N, &n) && N|n) {
        getchar();
        for(int i = 0; i < N; ++i)
            gets(grid[i]);
        for(int i = 0; i < n; ++i)
            gets(m[i]);

        printf("%d", intersections(n, N));
        for(int i = 0; i < 3; ++i) {
            rotate(n);
            printf(" %d", intersections(n, N));
        }
        printf("\n");
    }
    return 0;
}
