#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        ll ans = 0;
        multiset<ll> st;
        while(n--) {
            ll k, x;
            for(scanf("%lld", &k); k--; ) {
                scanf("%lld", &x);
                st.insert(x);
            }
            ans += *st.rbegin() - *st.begin();
            st.erase(prev(st.end()));
            st.erase(st.begin());
        }
        printf("%lld\n", ans);
    }
    return 0;
}
