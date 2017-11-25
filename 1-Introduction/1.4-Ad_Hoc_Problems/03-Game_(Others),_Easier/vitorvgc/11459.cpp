#include <bits/stdc++.h>

#define MAX 1100100

using namespace std;

unordered_map<int, int> mp;

int jog[MAX], die[MAX];

int main() {

    int t, a, b, c;
    for(scanf("%d", &t); t--; ) {
        scanf("%d %d %d", &a, &b, &c);
        mp.clear();
        while(b--) {
            int x, y;
            scanf("%d %d", &x, &y);
            mp[x] = y;
        }
        for(int i = 0; i < c; ++i)
            scanf("%d", &die[i]);

        int cur = 0;
        for(int i = 0; i < a; ++i)
            jog[i] = 1;
        
        for(int i = 0; i < c; ++i) {
            jog[cur] = min(100, jog[cur] + die[i]);

            if(mp.find(jog[cur]) != mp.end()) jog[cur] = mp[jog[cur]];
            if(jog[cur] == 100) break;

            cur = (cur + 1) % a;
        }
        
        for(int i = 0; i < a; ++i)
            printf("Position of player %d is %d.\n", i+1, jog[i]);
    }
    return 0;
}
