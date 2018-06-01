#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    while (scanf("%d", &n) != EOF && n) {
    	multiset<ll> ms;
    	ll cost = 0, v;
    	for (int i = 0, k; i < n; i++) {
    		scanf("%d", &k);
    		for (int j = 0; j < k; j++) {
    			scanf("%lld", &v);
    			ms.insert(v);
    		}
    		cost += *ms.rbegin() - *ms.begin();
    		ms.erase(ms.begin());
    		ms.erase(prev(ms.end()));
    	}
    	printf("%lld\n", cost);
    }
    return 0;
}