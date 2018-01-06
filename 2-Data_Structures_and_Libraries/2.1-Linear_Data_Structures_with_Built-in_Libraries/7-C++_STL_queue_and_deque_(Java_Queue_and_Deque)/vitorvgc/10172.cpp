#include <bits/stdc++.h>

using namespace std;

queue<int> stations[110];

int main() {
    int t;
    for(scanf("%d", &t); t--; ) {
        unsigned n, s, q, remaining = 0;
        stack<int> stk;

        scanf("%d %d %d", &n, &s, &q);
        for(int i = 0, m, x; i < n; ++i) {
            stations[i] = queue<int>();
            for(scanf("%d", &m); m--; ) {
                scanf("%d", &x);
                stations[i].push(x-1);
                ++remaining;
            }
        }

        int t = 0;
        for(int i = 0; remaining; i = (i+1) % n) {
            
            while(!stk.empty()) {
                if(stk.top() == i)
                    stk.pop(), ++t, --remaining;
                else if(stations[i].size() < q)
                    stations[i].push(stk.top()), stk.pop(), ++t;
                else break;
            }

            while(!stations[i].empty() && stk.size() < s) {
                stk.push(stations[i].front());
                stations[i].pop();
                ++t;
            }

            if(remaining) t += 2;
        }

        printf("%d\n", t);
    }
    return 0;
}
