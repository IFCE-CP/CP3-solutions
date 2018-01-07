#include <bits/stdc++.h>

using namespace std;

map< vector<int>, int > mp;

int main() {
    int n;
    while(scanf("%d", &n) && n) {

        mp.clear();
        while(n--) {
            vector<int> v(5);
            for(int i = 0; i < 5; ++i)
                scanf("%d", &v[i]);
            sort(v.begin(), v.end());
            ++mp[v];
        }

        int p = 0, ans = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            if(it->second > p)
                ans = p = it->second;
            else if(it->second == p)
                ans += p;
        }

        printf("%d\n", ans);
    }
    return 0;
}
