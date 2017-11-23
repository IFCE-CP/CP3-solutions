#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b, h, w;
    while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
        
        int ans = INT_MAX;
        while(h--) {
            int p, x;
            scanf("%d", &p);
            for(int i = 0; i < w; ++i) {
                scanf("%d", &x);
                if(x >= n && n * p <= b)
                    ans = min(ans, n * p);
            }
        }
        if(ans <= b) 
            printf("%d\n", ans);
        else
            printf("stay home\n");
    }
    return 0;
}
