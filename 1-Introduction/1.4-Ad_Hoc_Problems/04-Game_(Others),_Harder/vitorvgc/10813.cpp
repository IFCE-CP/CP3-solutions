#include <bits/stdc++.h>

using namespace std;

int m[5][5];
bool marked[5][5];

void mark(int x) {
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            if(m[i][j] == x)
                marked[i][j] = true;
}

bool won() {
    
    bool w = false;
    for(int i = 0; i < 5; ++i) {
        w = true;
        for(int j = 0; j < 5; ++j)
            w &= marked[i][j];
        if(w) return true;
    }

    for(int i = 0; i < 5; ++i) {
        w = true;
        for(int j = 0; j < 5; ++j)
            w &= marked[j][i];
        if(w) return true;
    }

    bool d1 = true, d2 = true;
    for(int i = 0; i < 5; ++i) {
        d1 &= marked[i][i];
        d2 &= marked[i][4-i];
    }
    return d1 || d2;
}

int main() {
    int t;
    for(scanf("%d", &t); t--; ) {

        memset(marked, false, sizeof marked);
        marked[2][2] = true;
        m[2][2] = 0;              
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                if(!(i == 2 && j == 2))
                    scanf("%d", &m[i][j]);
        
        int ans = -1;
        for(int x, i = 1; i <= 75; ++i) {
            scanf("%d", &x);
            if(ans != -1) continue;
            mark(x);
            if(won()) ans = i;
        }

        printf("BINGO after %d numbers announced\n", ans);
    }
    return 0;
}
