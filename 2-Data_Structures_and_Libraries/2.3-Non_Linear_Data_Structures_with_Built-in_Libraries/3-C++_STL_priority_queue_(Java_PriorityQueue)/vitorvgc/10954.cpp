#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0, x; i < n; ++i) {
            scanf("%d", &x);
            pq.push(x);
        }
        int ans = 0;
        while(pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            pq.push(x + y);
            ans += x + y;
        }
        printf("%d\n", ans);
    }
    return 0;
}
