#include <bits/stdc++.h>

using namespace std;

bool used[60];

int main() {
    
    int a[3], b[2];
    while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1]) && a[0]) {
    
        int wins = 0;
        memset(used, 0, sizeof used);
        used[a[0]] = used[a[1]] = used[a[2]] = used[b[0]] = used[b[1]] = true;

        vector<int> c(a, a+3);

        sort(c.begin(), c.end());
        sort(b, b+2);

        for(int i = 0; i < 2; ++i) {
            auto it = upper_bound(c.begin(), c.end(), b[i]);
            if(it == c.end()) it = c.begin(), ++wins;
            c.erase(it);
        }

        int ans;
        if(wins == 2) ans = 1;
        else if(wins == 1) ans = c[0] + 1;
        else ans = -1;

        for(; ans != -1 && used[ans]; ++ans);
        if(ans > 52) ans = -1;

        printf("%d\n", ans);
    }
    return 0;
}
