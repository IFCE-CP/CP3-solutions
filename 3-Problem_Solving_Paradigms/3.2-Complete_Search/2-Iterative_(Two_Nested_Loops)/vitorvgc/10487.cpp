#include <bits/stdc++.h>

using namespace std;

int l[1010];

int main() {
    int n, m, caso = 0;
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &l[i]);

        vector<int> v;
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                v.push_back(l[i] + l[j]);

        sort(v.begin(), v.end());

        printf("Case %d:\n", ++caso);
        for(scanf("%d", &m); m--; ) {
            int x, ans;
            scanf("%d", &x);

            auto it = lower_bound(v.begin(), v.end(), x);

            if(it == v.end())
                ans = *(it-1);
            else if(it == v.begin())
                ans = *it;
            else
                ans = (abs(x - *it) < abs(x - *(it-1)) ? *it : *(it-1));

            printf("Closest sum to %d is %d.\n", x, ans);
        }

    }
    return 0;
}
