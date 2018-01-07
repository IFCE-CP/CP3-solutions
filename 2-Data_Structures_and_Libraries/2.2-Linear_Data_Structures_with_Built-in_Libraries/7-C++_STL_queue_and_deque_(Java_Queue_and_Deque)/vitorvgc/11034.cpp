#include <bits/stdc++.h>

#define MAX 10100

using namespace std;

typedef pair<int, int> pii;

pii lenght[MAX];
bool crossed[MAX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    for(cin >> t; t--; ) {
        int l, m;
        memset(crossed, 0, sizeof crossed);
        cin >> l >> m;
        l *= 100;
        for(int i = 0; i < m; ++i) {
            int x;
            string s;
            cin >> x >> s;
            lenght[i] = pii(x, s == "left");
        }

        int ans = 0;
        bool onLeft = true;
        for(int i = 0; i < m; ) {
            
            while(i < m && crossed[i]) ++i;

            if(i >= m) break;

            int x = 0;
            for(int j = i; j < m && x <= l; ++j)
                if(lenght[j].second == onLeft && !crossed[j]) {
                    if(lenght[j].first + x <= l)
                        x += lenght[j].first, crossed[j] = true;
                    else break;
                }
            
            onLeft = !onLeft;
            ++ans;
        }

        cout << ans << '\n';
    }
    return 0;
}
