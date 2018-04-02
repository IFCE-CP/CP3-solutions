#include <bits/stdc++.h>

using namespace std;

bitset<20> rw, ld, rd;
vector< vector<int> > sol;
int row[8]; 

void solve(int c = 0) {

    if(c == 8) {
        sol.push_back(vector<int>(row, row + 8));
        return;
    }

    for(int r = 0; r < 8; ++r) {
        if(!rw[r] && !ld[r - c + 7] && !rd[r + c]) {
            row[c] = r;
            rw[r] = ld[r - c + 7] = rd[r + c] = true;
            solve(c + 1);
            rw[r] = ld[r - c + 7] = rd[r + c] = false;
        }
    }
}

int main() {

    vector<int> v(8);
    int caso = 0;

    rw = ld = rd = false;
    solve();

    while(scanf("%d", &v[0]) != EOF) {
        --v[0];
        for(int i = 1; i < 8; ++i) {
            scanf("%d", &v[i]);
            --v[i];
        }

        int ans = 8;
        for(auto &w : sol) {
            int diff = 0;
            for(int i = 0; i < 8; ++i)
                diff += (v[i] != w[i]);
            ans = min(ans, diff);
        }

        printf("Case %d: %d\n", ++caso, ans);
    }

    return 0;
}
