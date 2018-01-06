#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> mp;

int main() {
    int t, n, x;
    for(scanf("%d", &t); t--; ) {
        int ans = 0, start = 0;
        mp.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            auto it = mp.find(x);
            if(it != mp.end() && it->second >= start)
                start = it->second + 1;
            mp[x] = i;
            ans = max(ans, i - start + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
