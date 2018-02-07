#include <bits/stdc++.h>

#define MAXN 10100
#define MAXH 1000100

using namespace std;

string names[MAXN];
pair<int, int> cnt[MAXH];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    for(cin >> t; t--; ) {
        cin >> n;
        int mx = 0;
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int l, h;
            cin >> names[i] >> l >> h;
            mx = max(mx, h+1);
            ++cnt[l].first;
            --cnt[h+1].first;
            cnt[l].second += i;
            cnt[h+1].second -= i;
        }

        for(int i = 1; i <= mx; ++i) {
            cnt[i].first += cnt[i-1].first;
            cnt[i].second += cnt[i-1].second;
        }

        int q, p;
        for(cin >> q; q--; ) {
            cin >> p;
            cout << (cnt[p].first == 1 ? names[cnt[p].second] : "UNDETERMINED") << '\n';
        }

        if(t) cout << '\n';
    }
    return 0;
}
