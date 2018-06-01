#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
    	map<int, vector<int>> miv;
    	for (int i = 1, c; i <= n; i++) {
    		scanf("%d", &c);
    		miv[c].push_back(i);
    	}
    	for (int i = 0, k, v; i < m; i++) {
    		scanf("%d %d", &k, &v);
    		if (miv[v].size() >= k)
    			printf("%d\n", miv[v][k - 1]);
    		else printf("0\n");
    	}
    }
    return 0;
}