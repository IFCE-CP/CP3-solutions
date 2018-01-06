#include <bits/stdc++.h>

#define MAX 10100

using namespace std;

typedef pair<int, int> pii;

int times[MAX];
pii l[MAX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    for(cin >> tests; tests--; ) {
        int n, t, m;
        memset(times, -1,sizeof times);
        cin >> n >> t >> m;
        for(int i = 0; i < m; ++i) {
            int x;
            string s;
            cin >> x >> s;
            l[i] = pii(x, s == "left");
        }

        int now = l[0].first;
        bool onLeft = true;

        for(int i = 0; i < m;) {
            
            while(i < m && times[i] > -1) ++i;

            if(l[i].first > now) now = l[i].first;

            for(int j = i, k = 0; j < m && k < n && l[j].first <= now; ++j)
                if(l[j].second == onLeft && times[j] == -1)
                    times[j] = now + t, ++k;

            onLeft = !onLeft;
            now += t;
        }
        
        for(int i = 0; i < m; ++i)
            cout << times[i] << '\n';

        if(tests) cout << '\n';
    }
    return 0;
}
