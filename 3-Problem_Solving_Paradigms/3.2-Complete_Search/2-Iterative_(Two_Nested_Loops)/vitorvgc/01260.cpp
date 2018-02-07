#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main() {
    int t, n;
    for(scanf("%d", &t); t; --t) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        int ans = 0;
        for(int i = 1; i < n; ++i) {
            int b = 0;
            for(int j = 0; j < i; ++j)
                b += (a[j] <= a[i]);
            ans += b;
        }

        printf("%d\n", ans);
    }
    return 0;
}
