#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll a[25];

int main() {
    int t;
    for(scanf("%d", &t); t; --t) {
        ll n, d, k;

        scanf("%lld", &n);
        for(int i = 0; i <= n; ++i)
            scanf("%lld", &a[i]);
        scanf("%lld %lld", &d, &k);

        ll x = 0, mx = 0, sum = d;
        while(mx < k) {
            mx += sum;
            sum += d;
            ++x;
        }

        ll ans = 0, pot = 1;
        for(int i = 0; i <= n; ++i) {
            ans += a[i] * pot;
            pot *= x;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
