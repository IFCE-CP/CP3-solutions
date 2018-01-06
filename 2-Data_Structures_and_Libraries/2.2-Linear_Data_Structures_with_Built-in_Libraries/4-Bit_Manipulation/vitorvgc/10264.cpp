#include <bits/stdc++.h>

#define switchedBit(b, i) ((b) ^ (1 << (i)))

using namespace std;

int w[1 << 16], p[1 << 16];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {

        int q = 1 << n;

        for(int i = 0; i < q; ++i)
            scanf("%d", &w[i]);

        for(int i = 0; i < q; ++i) {
            p[i] = 0;
            for(int j = 0; j < n; ++j)
                p[i] += w[switchedBit(i, j)];
        }

        int ans = 0;
        for(int i = 0; i < q; ++i)
            for(int j = 0; j < n; ++j)
                ans = max(ans, p[i] + p[switchedBit(i, j)]);

        printf("%d\n", ans);
    }
    return 0;
};
