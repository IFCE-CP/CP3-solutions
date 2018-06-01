#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t, n, sf;
    for (scanf("%d", &t); t > 0; t--) {
        map<int, int> mp;
        int best = 0, s = 0, e = 0;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            if (i < n)
                scanf("%d", &sf);
            if (i == n || (mp.find(sf) != mp.end() && mp[sf] >= s)) {
                best = max(best, e - s);
                s = mp[sf] + 1;
            }
            e++;
            mp[sf] = i;
        }
        printf("%d\n", best);
    }
    return 0;
}