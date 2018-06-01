#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    while (scanf("%d %d", &n, &m) != EOF && n + m) {
    	map<int, int> mp;
    	int res = 0;
    	for (int i = 0, c; i < n; i++) {
    		scanf("%d", &c);
    		mp[c]++;
    	}
    	for (int i = 0, c; i < m; i++) {
    		scanf("%d", &c);
    		if (mp[c])
    			res++;
    	}
    	printf("%d\n", res);
    }
    return 0;
}