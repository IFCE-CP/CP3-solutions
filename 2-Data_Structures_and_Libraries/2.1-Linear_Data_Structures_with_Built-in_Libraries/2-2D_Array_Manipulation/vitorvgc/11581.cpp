#include <bits/stdc++.h>

using namespace std;

typedef vector< vector<int> > matrix;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

inline int inside(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

matrix f(matrix m) {
    
    matrix m2 = m;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j) {
            int s = 0;
            for(int k = 0; k < 4; ++k) {
                int x = j + dx[k];
                int y = i + dy[k];
                if(inside(x, y)) s += m[y][x];
            }
            m2[i][j] = s % 2;
        }
    return m2;
}

bool isZero(matrix m) {

    bool zero = true;
    for(int i = 0; i < 3 && zero; ++i)
        for(int j = 0; j < 3 && zero; ++j)
            zero &= !m[i][j];
    return zero;
}

int main() {
    int t;
    for(scanf("%d", &t); t--; ) {

        matrix m(3, vector<int>(3));

        for(int i = 0, x; i < 3; ++i) {
            scanf("%d", &x);
            m[i][0] = x / 100;
            m[i][1] = (x % 100) / 10;
            m[i][2] = x % 10;
        }

        int ans;
        for(ans = -1; !isZero(m); m = f(m), ++ans);
        printf("%d\n", ans);
    }
    return 0;
}
