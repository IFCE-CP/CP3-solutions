#include <bits/stdc++.h>

using namespace std;

int towers[25];
pair<int, int> intersections[15];

int main() {

    int n, m, k, t = 0;
    while(scanf("%d %d", &n, &m) && n|m) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &towers[i]);
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            int q, x, idx = 0;
            for(scanf("%d", &q); q--; ) {
                scanf("%d", &x);
                idx |= (1 << (x-1));
            }
            intersections[i].first = idx;
            scanf("%d", &intersections[i].second);
        }

        int ans = -1, maxValue = -1;
        for(int x = 0; x < (1 << n); ++x) {
            
            if(__builtin_popcount(x) != m) continue;

            int value = 0;
            for(int i = 0; i < n; ++i)
                if(x & (1 << i))
                    value += towers[i];

            for(int i = 0; i < k; ++i) {
                int q = __builtin_popcount(x & intersections[i].first);
                if(q > 1)
                    value -= (q-1) * intersections[i].second;
            }

            if(value > maxValue)
                maxValue = value, ans = x;
            else if(value == maxValue) {
                bool lower = false;
                for(int x2 = x, ans2 = ans; x2 || ans2; ) {
                    int bx = (x2 & -x2), by = (ans2 & -ans2);
                    if(bx < by) {
                        lower = true;
                        break;
                    }
                    else if(bx == by)
                        x2 -= bx, ans2 -= by;
                    else
                        break;
                }
                if(lower)
                    maxValue = value, ans = x;
            }
        }

        printf("Case Number  %d\n", ++t);
        printf("Number of Customers: %d\n", maxValue);
        printf("Locations recommended:");
        for(int i = 0; i < n; ++i)
            if(ans & (1 << i))
                printf(" %d", i+1);
        printf("\n\n");
    }
}
