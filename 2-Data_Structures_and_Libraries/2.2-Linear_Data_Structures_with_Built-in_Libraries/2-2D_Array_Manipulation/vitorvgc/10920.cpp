#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ll n, p;
    while(scanf("%lld %lld", &n, &p) && n|p) {
        
        ll k = 0, cur = 1;
        ll x = (n+1)/2, y = (n+1)/2;

        for(int i = 0; cur < p; i = (i+1) % 4) {

            if(!(i & 1)) ++k;

            ll q = min(k, p - cur);
            x += q * dx[i];
            y += q * dy[i];

            cur += q;
        }

        printf("Line = %lld, column = %lld.\n", y, x);
    }
    return 0;
}
