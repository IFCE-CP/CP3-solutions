#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, x, ans, caso = 0;
    for(scanf("%d", &t); t; --t) {
        ans = INT_MIN;
        for(scanf("%d", &n); n; --n) {
            scanf("%d", &x);
            ans = max(ans, x);
        }
        printf("Case %d: %d\n", ++caso, ans);
    }
    return 0;
}
