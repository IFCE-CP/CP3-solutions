#include <bits/stdc++.h>

using namespace std;

int m[10][10];

int main() {
    int t, n;
    for(scanf("%d", &t); t--; ) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &m[i][j]);

        vector<int> v(n);
        for(int i = 0; i < n; ++i)
            v[i] = i;

        int ans = INT_MAX;
        do {
            int x = 0;
            for(int i = 0; i < n; ++i)
                x += m[i][v[i]];
            ans = min(ans, x);
        } while(next_permutation(v.begin(), v.end()));

        printf("%d\n", ans);
    }
    return 0;
}
